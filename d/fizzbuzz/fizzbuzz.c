#include <stdio.h>

/* function to print numbers or words based on divisibility */
int main(void)
{
  int i;
  for (i = 1; i < 101; i++) /* print numbers between 0-100 */
    {if (i % 5 == 0 && i % 3 == 0) /* if i is divisible by 3 and 5 */
	{printf("FizzBuzz");
	 printf(" ");}
      if (i % 5 == 0 && i % 3 != 0) /* if i is divisible by 5 */
	{if (i == 100) /* if i is 100, do not add space after */
	    {printf("Buzz");}
	  else /* if i is not 100, add space after */
	    {printf("Buzz");
	     printf(" ");}
	}
      if (i % 3 == 0 && i % 5 != 0) /* if i is divisible by 3 */
	{printf("Fizz");
	 printf(" ");}     
      if (i % 5 != 0 && i % 3 != 0) /* otherwise, just print the number */
	{printf("%d", i);
	 printf(" ");}
    }
  return 0;
}
