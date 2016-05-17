/* determines size of a grid of characters (array of strings) */
int grid_size(char **grid)
{
	int i;

	i = 0;

	while (*grid != 0) 	/* until there is no pointer */
	{
		i++;	     /* increase counter */
		grid++;     /* pointer arithmetic for next pointer */
	}

	return i;
}
