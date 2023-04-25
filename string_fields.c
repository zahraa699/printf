#include "main.h"

/**
 * get_precision - this function gets precision from format string
 * @p: the format string
 * @params: the struct of params
 * @ap: the argument pointer
 *
 * Description: this function precision from format string
 *
 * Return: the returned value are new pointer
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}