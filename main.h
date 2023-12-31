#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -2   
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
/**
 * struct parameters - struct for parameters
 * @plus_flag: bool value to specify a plus flag
 * @space_flag: bool value to specify a space flag
 * @hashtag_flag: bool value to specify a hashtag flag
 * @zero_flag: bool value to specify a zero flag
 * @minus_flag: bool value to specify a minus flag
 * @h_modifier: bool value to specifiy h_modifier
 * @l_modifier: bool value to specify l_modifier
 */

typedef struct parameters
{
  unsigned int unsign : 1;
  unsigned int plus_flag : 1;
  unsigned int space_flag : 1;
  unsigned int hashtag_flag : 1;
  unsigned int zero_flag : 1;
  unsigned int minus_flag : 1;
  unsigned int width;
  unsigned int percision;
  unsigned int h_modifier  :  1;
  unsigned int l_modifier  :  1;
}params_t;
/**
 * struct specifier - a Struct that specifies,
 *                                            the input token type
 * @specifier: format token (i.e %d,%s,%c)
 * @f: The function associated.
 */

typedef struct specifier
{
  char *specifier;
  int (*p)(va_list ap, params_t *);

} specifier_t;
/* params.c module*/
void init_params(params_t *params, va_list ap);
/* _puts.c module */
int _puts(char *str);
int _putchar(int c);
/* convert_num.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);


/* print_functions.c module*/
int print_int(va_list ap, params_t *params);
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
/*string_fields.c module*/
char *get_precision(char *p, params_t *params, va_list ap);
/* specifier.c module*/
int (*get_specifier(char *s)) (va_list, params_t *params);
int get_print_function(char *s, va_list ap, params_t *params);
int get_flag(char *s,params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);
/*printer.c module*/
int print_from_start_to_end (char *start, char *end, char *skip);
int print_reverse(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t params);
int print_address(va_list ap, params_t *params);
/*numbers.c module*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);

/*print_number.c module*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str,params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);
/* _printf.c module */
int _printf(const char *format, ...);
#endif
