#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFF_SIZE 32

int print_char(char c);
int print_file(int len, int fd, char buffer[BUFF_SIZE + 1]);
int handle_args(int argc, char **argv);
void print_string(char *str);

int main(int argc, char **argv) {
  int err;
  char c;

  if (argc == 1) {
    /* If read is successful, prompt for another char. */
    while((err = read(0, &c, 1)))
    {
      /* If the user enters CTRL-D, break out of the loop. */
      if (c == 4) break;
      write(1, &c, 1);
    }
    if (err == -1) { /* Handle err return value. */
      perror("read");
      return (1);
    }
  }
  if (argc > 1) {
    err = handle_args(argc, argv);
    if (err == 1) {
      return (1);
    }
  }
  return (0);
}

int handle_args(int argc, char **argv) {
  int fd, len, err, i;
  char buffer[BUFF_SIZE + 1];
  for(i = 1; argc > 1; ++i) {
    fd = open(argv[i], O_RDWR);
    if (fd == -1) {
      print_string("3-cat: "); /* Print error message. */
      perror(argv[i]);
    }
    if (fd != -1) {
      len = read(fd, buffer, BUFF_SIZE);
      if (len == -1) {
        close(fd);
        return(1);
      }
      buffer[len] = '\0';
      err = print_file(len, fd, buffer);
      if (err == -1) {
        return (1);
      }
    }
    --argc;
    close(fd);
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
    len = read(fd, buffer, BUFF_SIZE); /* Move to next 32 characters. */
    if (len == -1) {
      close(fd);
      return(1);
    }
  }
  buffer[len] = '\0'; /* Add NULL terminator and call print_buff. */
  for(i = 0; buffer[i] != '\0'; ++i) {
    c = buffer[i];
    err = write(1, &c, 1);
    if (err == -1) {
      return (1);
    }
  }
  return(0);
}

void print_string(char *str) {
  int i;
  for(i = 0; str[i] != '\0'; ++i) {
    /* Print each char in a string. */
    print_char(str[i]);
  }
}
