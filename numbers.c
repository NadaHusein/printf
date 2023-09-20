#include "main.h"
/**
 * convert - converter function
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: parameter struct
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
  static char *array;
  static char buffer[50];
  char sign = 0;
  char *ptr;
  unsigned long n = num;
  (void) params;
  if (!(flags & CONVERT_UNSIGNED ) && num < 0)
    {
      n = num;
      sign = '-';

    }
  array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
  ptr=&buffer[49];
  *ptr = '\0';
  do
    {
      *--ptr = array[n % base];
      n /= base;
    } while(n != 0);
  if (sign)
    *--ptr = sign;
  return (ptr);
}
/***
 * print_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameter struct
 * Return: bytes to be printed
 */
int print_unsigned(va_list ap, params_t *params)
{
  unsigned long l;
  if(params->l_modifier)
    l = (unsigned long) va_arg(ap, unsigned long);
  else if(params->h_modifier)
    l = (unsigned short int) va_arg(ap, unsigned int);
  else
    l = (unsigned int) va_arg(ap, unsigned int);
  params->unsign = l;
  return (print_number(convert(l,10,CONVERT_UNSIGNED,params),params));
}