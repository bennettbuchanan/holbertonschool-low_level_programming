#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int err;
  char c;

  /* If read is successful, prompt for another char. */
  while((err = read(0, &c, 1)))
  {
    /* If the user enters CTRL-D, break out of the loop. */
    if (c == 4) break;
    write(1, &c, 1);
  }
  /* Handle err return value. */
  if (err == -1) {
    perror("read");
    return (1);
  }

  return (0);
}
