#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFF_SIZE 32

int print_char(char c);
int print_file(int len, int fd, char buffer[BUFF_SIZE + 1]);

int main(int argc, char **argv) {
  int fd, len, err, i, j;
  char buffer[BUFF_SIZE + 1];
  char input[BUFF_SIZE + 1];
  char c;

  if (argc == 1) {
    len = read(0, input, BUFF_SIZE);
    input[len] = '\0';

    while(input[len] < BUFF_SIZE) {
      input[len] = '\0';
      for(i = 0; input[i] != '\0'; ++i) {
        c = input[i];
        err = write(1, &c, 1);
        if (err == -1) {
          perror("write");
          return (1);
        }
      }
      /* Move to next series 32 of characters. */
      len = read(0, input, BUFF_SIZE);
      if (len == -1) {
        perror("read");
        return(1);
      }
    }
    /* Add NULL terminator and call print_buff. */
    input[len] = '\0';
    /* Print the remaining characters. */
    for(i = 0; input[i] != '\0'; ++i) {
      c = input[i];
      err = write(1, &c, 1);
      if (err == -1) {
        perror("write");
        return (1);
      }
    }

    if (err == -1) {
      perror("write");
      return (1);
    }
    return (0);
  }

  for (j = 1; argc > 1; --argc) {
    fd = open(argv[j], O_RDWR | O_CREAT);
    if (fd == -1) {
      perror("open");
      return (1);
    }

    len = read(fd, buffer, BUFF_SIZE);
    if (len == -1) {
      perror("read");
      close(fd);
      return(1);
    }

    /* Add NULL terminator and call print_file. */
    buffer[len] = '\0';

    err = print_file(len, fd, buffer);
    if (err == -1) {
      return (1);
    }

    close(fd);
    ++j;
  }

  return (0);
}

int print_file(int len, int fd, char buffer[BUFF_SIZE + 1]) {
  int i, err;
  char c;

  while(buffer[len] < BUFF_SIZE) {
    buffer[len] = '\0';
    for(i = 0; buffer[i] != '\0'; ++i) {
      c = buffer[i];
      err = write(1, &c, 1);
      if (err == -1) {
        perror("write");
        return (1);
      }
    }
    /* Move to next series 32 of characters. */
    len = read(fd, buffer, BUFF_SIZE);
    if (len == -1) {
      perror("read");
      close(fd);
      return(1);
    }
  }
  /* Add NULL terminator and call print_buff. */
  buffer[len] = '\0';
  /* Print the remaining characters. */
  for(i = 0; buffer[i] != '\0'; ++i) {
    c = buffer[i];
    err = write(1, &c, 1);
    if (err == -1) {
      perror("write");
      return (1);
    }
  }
  return(0);
}
