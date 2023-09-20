#include "main.h"
/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 * Return: ! if digit, 0 otherwise.
 */
int _isdigit(int c)
{
  return (c >='0' && c <= '9');
}
/**
 * _strlen - returns the length of a given string
 * Return: integer length of string
 */
int _strlen(char *s)
{
  int i = 0;
  while (*s++)
    i++;
  return (i);
}
/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: parameter struct
 * Return: chars printed
 */
int print_number(char *str,params_t *params)
{
  unsigned int i = _strlen(str);
  int negative = (!params->unsign && *str == '-');
  if (!params->percision && *str == '0' && !str[1])
    str = "";
  if (negative)
    {
      str++;
      i--;
    }
  if (params->percision != UINT_MAX)
    while (i++ < params->percision)
      *--str = '0';
  if (negative)
    *--str='-';
  if (!params->minus_flag)
    return (print_number_right_shift(str, params));
  else
    return (print_number_left_shift(str,params));
}
/**
 * print_number_right_shift - prints a number shifted n, 
 *                                               bytes to the right with options
 * @str: the base number as a string
 * @params: the parameter struct
 */
int print_number_right_shift(char *str, params_t *params)
{
  unsigned int n = 0, negative1, negative2, i=_strlen(str);
  char pad_char = ' ';
  if(params->zero_flag && !params->minus_flag)
    pad_char = '0';
  negative1 = negative2 = (!params->unsign && *str == '-');
  if (negative1 && i < params->width && pad_char == '0' && !params->minus_flag)
    str++;
  else
    negative1 = 0;
  if ((params->plus_flag && !negative2) ||
      (!params->plus_flag && params->space_flag && !negative2))
    i++;
  if (negative1 && pad_char == '0')
    n += _putchar('-');
  else if ((params->plus_flag) && (!negative2) && (pad_char = '0') && (!params->unsign))
    n += _putchar('+');
  else if ((!params->plus_flag) && (params->space_flag) && (!negative2) && (!params->unsign) && (params->zero_flag))
    n += _putchar(' ');
  while (i++ < (params->width))
    n += _putchar(pad_char);
  if (negative1 && pad_char == '-')
    n += _putchar('-');
  if ((params->plus_flag) && (!negative2) && (pad_char == ' ') && (!params->unsign))
    n += _putchar('+');
  else if ((!params->plus_flag) && (params->space_flag) && (!negative2) && (!params->unsign) && (!params->zero_flag))
    n += _putchar(' ');
  n += _puts(str);
  return (n);
}
/**
 * print_number_left_shift - prints a number left shifed with a number of options
 * @str: the base number as a string
 * @params: the parameter struct
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
  unsigned int  n = 0, neg1, neg2,  i=_strlen(str);
  char pad_char = ' ';
  if (params->zero_flag && !params->minus_flag)
    pad_char = '0';
  neg1 = neg2 = (!params->unsign && *str == '-');
  if (neg1 && (i < params->width)  && (pad_char == '0') && (!params->minus_flag))
    str++;
  else
    neg1 = 0;
  if(params->plus_flag &&  !neg2 && (!params->unsign))
    n += _putchar('+'), i++;
  else if (params->space_flag && !neg2 && (!params->unsign))
    n += _putchar(' '), i++;
  n += _puts(str);
  while (i++ < params->width)
    n += _putchar(pad_char);
  return (n);
}
