#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env) {
  pid_t pid;
  char *exec_argv[] = {"/bin/echo", "Holberton", NULL};
  int status;

  if ((pid = fork()) == -1) {
    perror("fork");
    return(1);
  }
  else if (pid == 0) {

    execve(exec_argv[0], exec_argv, env);
  }
  else {
    wait(&status);
    printf("Child process terminated.\n");
  }
  return(0);
}
