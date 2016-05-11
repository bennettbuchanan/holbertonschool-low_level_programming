#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int print_char(char c);

int main(int argc, char **argv) {
  struct stat fileStat;
  int err;
  if (argc != 2) return (1);
  err = lstat(argv[1], &fileStat);
  if (err == -1) {
    perror("lstat");
    return (1);
  }
  if (S_ISLNK(fileStat.st_mode)) {
    print_char('l'); /* Print the permissions of the symbolic link. */
  } else {
    S_ISDIR(fileStat.st_mode) ? print_char('d') : print_char('-');
  }
  fileStat.st_mode & S_IRUSR ? print_char('r') : print_char('-');
  fileStat.st_mode & S_IWUSR ? print_char('w') : print_char('-');
  fileStat.st_mode & S_IXUSR ? print_char('x') : print_char('-');
  fileStat.st_mode & S_IRGRP ? print_char('r') : print_char('-');
  fileStat.st_mode & S_IWGRP ? print_char('w') : print_char('-');
  fileStat.st_mode & S_IXGRP ? print_char('x') : print_char('-');
  fileStat.st_mode & S_IROTH ? print_char('r') : print_char('-');
  fileStat.st_mode & S_IWOTH ? print_char('w') : print_char('-');
  fileStat.st_mode & S_IXOTH ? print_char('x') : print_char('-');
  print_char('\n');
  return (0);
}
