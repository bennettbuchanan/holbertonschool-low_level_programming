#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFF_SIZE 32

int cp_file(int len, int fd, int f_cp, char buffer[BUFF_SIZE + 1]);

int main(int argc, char **argv) {
  int fd, f_cp, len, err;
  char buffer[BUFF_SIZE + 1];

  if (argc != 3) return (1);

  fd = open(argv[1], O_RDWR | O_CREAT);
  if (fd == -1) return (1);

  f_cp = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (f_cp == -1) return (1);

  len = read(fd, buffer, BUFF_SIZE);
  if (len == -1) return(1);

  buffer[len] = '\0'; /* Add NULL terminator and call cp_file. */
  err = cp_file(len, fd, f_cp, buffer);
  if (err == -1) return (1);

  close(fd);
  close(f_cp);
  return (0);
}

int cp_file(int len, int fd, int f_cp, char buffer[BUFF_SIZE + 1]) {
  int i, err;
  char c;

  while(buffer[len] < BUFF_SIZE) {
    buffer[len] = '\0';
    for(i = 0; buffer[i] != '\0'; ++i) {
      c = buffer[i];
      err = write(f_cp, &c, 1);
      if (err == -1) return (-1);
    }
    len = read(fd, buffer, BUFF_SIZE); /* Next series 32 of characters. */
    if (len == -1) return(-1);
  }
  buffer[len] = '\0'; /* Add NULL terminator and call print_buff. */
  for(i = 0; buffer[i] != '\0'; ++i) { /* Print the remaining characters. */
    c = buffer[i];
    err = write(f_cp, &c, 1);
    if (err == -1) return (-1);
  }
  return(0);
}
