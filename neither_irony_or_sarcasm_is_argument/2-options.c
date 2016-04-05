#include <stdio.h>

int main(int argc, char **argv) {
  int i, j, k;
  char S[1000];
  int h = 0;
  /* Loop through options given */
  for (i = 0; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0') {
      break;
    }
    if (argv[i][0] == '-' && argv[i][1] != '-' && argv[i][1] != '\0') {
      for (j = 1; argv[i][j] != '\0'; j++) {
        for (k = 0; S[k] != '\0'; k++) {
          if (S[k] == argv[i][j]) {
            break;
          }
          if (S[k] != argv[i][j] && S[k+1] == '\0') {
            printf("%c", argv[i][j]);

            if (argv[i+1][0] == '-' && argv[i+1][1] == '-' && argv[i+1][2] == '\0' && argv[i][j+1] == '\0') {
              break;
            }
            printf(", ");
          }
        }
        if (argv[i][j] != '\0') {
          S[h] = argv[i][j];
          h++;
        }
      }
    }
    if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] != '-') {
      if (argv[i][3] != '\0') {
        for (j = 2; argv[i][j] != '\0'; j++) {
          if (argv[i][j] == '-') {
            break;
          }
          printf("%c", argv[i][j]);
        }
        if (argv[i+1][0] == '-' && argv[i+1][1] == '-' && argv[i+1][2] == '\0') {
          break;
        }
        printf(", ");
      }
      if (argv[i][3] == '\0') {
        for (k = 0; S[k] != '\0'; k++) {
          if (S[k] == argv[i][2]) {
            break;
          }
          if (S[k] != argv[i][j] && S[k+1] == '\0') {
            printf("%c", argv[i][2]);
            if (argv[i+1][0] == '-' && argv[i+1][1] == '-' && argv[i+1][2] == '\0') {
              break;
            }
            printf(", ");
          }
        }
      }
    }
  }
  printf("\n");
	return (0);
}
