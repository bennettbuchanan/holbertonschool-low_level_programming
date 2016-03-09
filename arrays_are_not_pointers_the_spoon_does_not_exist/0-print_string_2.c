int print_char(char c);

void print_string_2(char *str)
{
	int i = 0;
	int j = 0;

	/* find length of string */
	while(str[i] != 0)
	{
		i++;
	}

	/* print every other character of string */
	while(j < i)
	{
		print_char(str[j]);
		j += 2;
	}
}
