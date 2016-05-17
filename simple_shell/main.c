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
 * Takes arguments from command line and locates them in PATH.
 * @cmd: The command entered by the user.
 * @str: The string entered by the user.
 * @env: The environment.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, __attribute__((unused)) char **argv, char **env)
{
        /*
         * @exec_argv stores the array of commands to be executed
         * @exec_size stores the number of strings in the array exec_argv
         */
	pid_t pid;
	int status, exec_size;
	/*char *path_to_exec;*/
	/* char *concat_str; */
	char **exec_argv;

 	/* check usage */
        if (usage(argc, 1, "No args please.\n"))
                return 1;

	while (1) {
                /* obtain commands entered by the user */
                exec_argv = prompt();
                /* obtain number of strings in the array */
		exec_size = grid_size(exec_argv);

                /* built-in command function */

		if (str_cmp(exec_argv[0], "exit") == 0) {
                        if (grid_size(exec_argv) == 1)
                                break;
                        if(usage(grid_size(exec_argv), 2, "Too many args for exit status. Returning 1.\n"))
                                return 1;
                        else
                                return atoi(exec_argv[1]);
                }

                /* handle the $? variable */
                if (WIFEXITED(status))
                        replace_expr("$?", WEXITSTATUS(status), exec_argv);

                /* linux OS command */

		if ((pid = fork()) == -1) {
			perror("fork");
			return 2;
		} else if (pid == 0) {
                        /* CHILD PROCESS */

                        execve(find_path(exec_argv[0], env), exec_argv, env);
			perror("execve");
			free_grid(exec_argv, exec_size);
                        /* If execve fails, this child process returns 3 */
			return 3;
		} else {
                        /* PARENT PROCESS */
                        wait(&status);
		}

		free_grid(exec_argv, exec_size);
	}

	free_grid(exec_argv, exec_size);
	return 0;
}

/*
 * This function handles the prompt until the user enters a command. Upon
 * receiving commands from the user, it returns the an array of strings
 * containing the command.
 */

char **prompt(void)
{
        char *raw_str, **exec_argv;

        /* keep prompting the user until something is entered */
        while (1) {
                print_prompt();
                raw_str = read_line(0);
                if (str_len(raw_str) != 0) {
                        exec_argv = string_split(raw_str, ' ');
                        /* frees the memory allocated in read_line() */
                        free(raw_str);
                        return exec_argv;
                }
        }
}

char usage(int argc, int expected, char *str)
{
	if (argc != expected) {
                print_string(str);
		return 1;
	}

        return 0;
}

void replace_expr(char *expr, int value, char **exec_argv)
{
        int i;

        for (i = 0; i < grid_size(exec_argv); i++) {
                if (str_cmp(exec_argv[i], expr) == 0) {
                        free(exec_argv[i]);
                        exec_argv[i] = int_to_string(value);
                }
        }
}
