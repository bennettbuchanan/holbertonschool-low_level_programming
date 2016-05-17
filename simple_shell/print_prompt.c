#include "header.h"

int *print_prompt(){
	int i;
	char *prompt = "GreenShell$ ";

	i = 0;
	while (prompt[i] != '\0') {
		print_char(prompt[i]);
		++i;
	}
	return 0;
}
