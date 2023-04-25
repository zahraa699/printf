#include "main.h"

/**
 * _printf - this function printed sum of bytes
 * @format : this paramater of format string
 *
 * Description: this function print sum number of bytes
 *
 * Return: the returned value are number of bytes
 */

int _printf(const char *format, ...)
{
	int addation = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (!format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')
		{
			addation += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			addation += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			addation += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (addation);
}
