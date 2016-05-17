#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <dirent.h>
#include "libshell/libshell.h"

/*
 * ch_dir() - Takes a path as parameter and uses the Linux builtin function
 * chdir to change the process to that directory. If the path is NULL, the
 * path is set to the user's home directory.
 * @path: The path to change directories to.
 * @env: The user's environment.
 *
 * Return: On success, zero is returned. On error, -1 is returned, and
 * errno is set appropriately.
 */
int ch_dir(char *path, char **env) {
        char *tmp;
        /*
         * Add code to track the "previous working directory" with set_env()
         * every time this function is called. Then, if `cd -` is used,
         * the path will be set to this environmental variable. See placeholder
         * code below.
         */

        /* setenv("OLDPWD") = get_env_var("PWD", env) */
        if (path == NULL) {
                path = get_env_var("HOME", env);
                tmp = path;
                free(path);
                return chdir(tmp);
        } else if (*path == '-') {
                path = get_env_var("OLDPWD", env);
                tmp = path;
                free(path);
                return chdir(tmp);
        }
        /* setenv("PWD") = get_env_var(path, env) */
        return chdir(path);
}
