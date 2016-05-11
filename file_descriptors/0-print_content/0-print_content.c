#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFF_SIZE 32

int print_buff(int len, int fd, char buffer[BUFF_SIZE + 1]);

int main(void) {
  int fd, len, err;
  char buffer[BUFF_SIZE + 1];

  fd = open("lorem_ipsum", O_RDWR | O_CREAT);
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
  /* Add NULL terminator and call print_buff. */
  buffer[len] = '\0';
  err = print_buff(len, fd, buffer);
  if (err == -1) {
    return (1);
  }
  close(fd);
  return (0);
}

int print_buff(int len, int fd, char buffer[BUFF_SIZE + 1]) {
  int i;

  while(buffer[len] < BUFF_SIZE) {
    buffer[len] = '\0';
    for(i = 0; buffer[i] != '\0'; ++i) {
      write(1, &buffer[i], 1);
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
    write(1, &buffer[i], 1);
  }
  return(0);
}
