int print_char(char c);
void print_second_half(int len, char *str);

void print_string_half(char *str)
{
	int len = 0;

	while(str[len] != 0) /* find length of string */
	{
		len++;
	}
	print_second_half(len, str);
}

void print_second_half(int len, char *str)
{
	int half;
	if (len %2 == 0) /* test evenness */
	{
		half = len / 2;
		for (; half < len; half++)
		{
			print_char(str[half]);
		}
	}
	else if (len %2 != 0)
	{
		half = (len / 2) + 1;
		for (; half < len; half++)
		{
			print_char(str[half]);
		}
	}
}
