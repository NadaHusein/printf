#include "main.h"
/**
 * print_from_start_to_end - prints a range of chars 
 * @start: starting position of pointer
 * @end: ending position
 * @skip: character to be skipped 
 */
int print_from_start_to_end (char *start, char *end, char *skip)
{
  int count =0;
  while (start <= end)
    {
      if(start != skip)
	count += _putchar(*start);
      start++;
    }
  return (count);
}
/**
 * print_reverse - prints a reversed string 
 * @ap: argument list (string)
 * @params: the parameter struct pointer
 * @Return: number of bytes to be printed 
 */
int print_reverse(va_list ap, params_t *params)
{
  int len, count = 0;
  char *str = va_arg(ap,char*);
  (void) params;
  if (str)
    {
      for (len = 0; *str; str++)
	len++;
      str--;
      for (; len > 0 ; len--, str-- )
	count += _putchar(*str);
    }
  return (count);
}
/**
 * print_rot13 - prints the string in rot13 format
 * @ap: arguments
 * @params: the parameters struct
 * 
 * Return: number of bytes printed
 */
int print_rot13(va_list ap, params_t params)
{
  int i = 0, index = 0 ;
  int count = 0;
  char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM          nopqrstuvwxyzabcdefghijklm ";
  char *a = va_arg(ap, char*);
  (void) params;
  while(a[i])
    {
      if ((a[i] >= 'A' && a[i] <= 'z') || (a[i] >= 'a' && a[i] <= 'z'))
	{
	  index = a[i] - 65;
	  count += _putchar(arr[index]);
	}
      else
	count += _putchar(a[i]);
      i++;
    }
  return (count);
}
/**
 * print-address - prints address
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *params)
{
  unsigned long int n = va_arg(ap,unsigned long int);
  char *str;
  if(!n)
    return (_puts("(nil)"));
  str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
  *--str = 'x';
  *--str = '0';
  return (print_number(str, params));
}
