#include <stdio.h>
 
int main()
{
  int i;
  for (i = 1; i < 101; i++)
    {
      if (i % 5 == 0 && i % 3 == 0)
	{
	  printf("FizzBuzz");
	  printf(" ");  
	}
      if (i % 5 == 0 && i % 3 != 0)
	{
	  if (i == 100)
	    {
	      printf("Buzz");
	    }
	  else
	    {
	      printf("Buzz");
	      printf(" ");
	    }
	}
      if (i % 3 == 0 && i % 5 != 0)
	{
	  printf("Fizz");
	  printf(" ");
	}     
      if (i % 5 != 0 && i % 3 != 0)
	{
	  printf("%d", i);
	  printf(" ");
	}
    }
  return 0;
}
