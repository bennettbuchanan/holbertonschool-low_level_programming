#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <dirent.h>
#include "libshell/libshell.h"

#define BUFFER_SIZE 100

/*
 * find_path() - Takes a command and searches the environmental variable
 * PATH for the command name.
 * @cmd: The command entered.
 * @env: The environment with the PATH variable.
 *
 * Return: The program if it exists, and NULL if the program is not found.
 * For example, if the cmd variable were the string "ls" and this program
 * exists in the /bin directory, this function will return the entire path
 * to that program: the string "/bin/ls".
 */
char *find_path(char *cmd, char **env) {
        DIR *dir;
        struct dirent *dir_search;
        char *path;
        char **arr;
        int i, exec_size;

        /*
         * Retrieve the value of the env variable PATH, then split it into
         * an array based on the colon separator. Free memory allocated in
         * get_env_var function.
         */
        path = get_env_var("PATH", env);
        arr = string_split(path, ':');
        exec_size = grid_size(arr);
        free(path);

        /* Increment through the path array, searching within dirs. */
        for(i = 0; arr[i] != '\0'; ++i) {
                if ((dir = opendir(arr[i])) == NULL) {
                        perror("opendir");
                        return NULL;
                }
                while((dir_search = readdir(dir)) != NULL) {
                        if (str_cmp(dir_search->d_name, cmd) == 0) {
                                arr[i] = concat_strings(arr[i], "/");
                                closedir(dir);
                                return concat_strings(arr[i], cmd);
                        }
                }
                closedir(dir);
        }
        free_grid(arr, exec_size);
        return NULL;
}

/*
 * get_env_var() - Takes an environmental variable and searches for its
 * existence. If found it will return the value of that variable.
 * @var: The environmental variable to be found (e.g., "PATH");
 * @env: The parent process environment.
 *
 * Return: The value of the variable, if it exists. NULL if it does
 * not exist.
 */
char *get_env_var(char *var, char **env) {
        char *var_str;
        char *val;
        int i, j, len, loc;

        var_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        val = malloc(sizeof(char) * (BUFFER_SIZE + 1));

        len = str_len(var);

        /* Find the location of the variable in the env array. */
        for(loc = 0; env[loc] != '\0'; loc++) {
                for(j = 0; j < len; ++j) {
                        var_str[j] = env[loc][j];
                        var_str[j + 1] = '\0';
                } if(str_cmp(var, var_str) == 0)
                          break;
                if(env[loc + 1] == '\0')
                        return NULL;
        }

        free(var_str);

        /* Store the value of the env variable to be returned. */
        for(i = 0; env[loc][i + (len + 1)] != '\0'; i++) {
                val[i] = env[loc][i + (len + 1)];
        }
        val[i] = '\0';

        return val;
}
