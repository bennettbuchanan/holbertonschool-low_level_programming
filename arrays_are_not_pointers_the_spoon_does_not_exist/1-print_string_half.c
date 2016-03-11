#include "my_functions.h"

void print_string_half(char *str)
{
	int i;
	int len = 0;

	while(str[len] != 0) /* find length of string */
	{
		len++;
	}

	if (len % 2 == 0) /* test evenness */
	{
		i = len / 2;
	}

	else if (len % 2 != 0) /* test oddness */
	{
		i = (len / 2) + 1;
	}

	for (; i < len; i++) /* print the second half */
		{
			print_char(str[i]);
		}
}
