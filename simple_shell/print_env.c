#include "header.h"

/*
 * print_env() - Prints the environmental variables to standard output.
 * @env: The current environment from the main function.
 *
 * Return: void.
 */
void print_env(char **env) {
        int i, j;
        for(i = 0; env[i] != '\0'; ++i) {
                for(j = 0; env[i][j] != '\0'; ++j) {
                        print_char(env[i][j]);
                }
                print_char('\n');
        }
}
