#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

int string_to_integer(char *s){
  int long i, n, temp, digit;
  int place = 0;
  int isNegative = 0;
  /* break out of loop when string reaches 0 in memory */
  for (i = 0; i >= 0; i++) {
    temp = i - 1;
    if (s[i] == 0){break;}
    else if (s[i] <= 47 || s[i] >= 58)
      {if (s[i] == 45) {isNegative += 1; }
	if (s[temp] > 47 && s[temp] < 58) {break;}}
    else if (s[i] > 47 && s[i] < 58)
      {digit = s[i] - 48;
	if (place == 0) {n = digit;
	  place += 1;
	  if (isNegative %2 != 0) {place += 1; }}
	else if (place > 0) {
	  n *= 10;
	  n += digit;
	  place += 1;}}}
  if (n == 2147483648 && place > 10) {return (n);}
  else if (n == 2147483648 && place == 10) {return 0;}
  else if (n > 2147483648) {return 0;}
  else {if (isNegative %2 != 0) {print_char('-');}
  return (n);}}
