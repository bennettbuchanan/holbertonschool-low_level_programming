#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFF_SIZE 32

int print_char(char c);
int cp_file(int len, int fd, int f_cp, char buffer[BUFF_SIZE + 1]);

int main(int argc, char **argv) {
  int fd, f_cp, len, err;
  char buffer[BUFF_SIZE + 1];

  if (argc != 3) return (1);

  fd = open(argv[1], O_RDWR | O_CREAT);
  if (fd == -1) {
    perror("open");
    return (1);
  }

  f_cp = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0777);
  if (f_cp == -1) {
    perror("open");
    return (1);
  }

  len = read(fd, buffer, BUFF_SIZE);
  if (len == -1) {
    perror("read");
    close(fd);
    return(1);
  }

  /* Add NULL terminator and call cp_file. */
  buffer[len] = '\0';

  err = cp_file(len, fd, f_cp, buffer);

  if (err == -1) {
    return (1);
  }

  close(fd);
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
    err = write(f_cp, &c, 1);
    if (err == -1) {
      perror("write");
      return (1);
    }
  }
  return(0);
}



/*

int main(void) {
  char ch;

  FILE* p = fopen("lorem_ipsum", "r");
  if (p == NULL) return (1);

  while((ch = fgetc(p)) != EOF) {
    print_char(ch);
  }

  if(fclose(p) == 1) return (1);

  return (0);
}

*/
