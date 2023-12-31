#include "main.h"
#include <stdarg.h>
/**
 * _printf - a function that produces output according to a format
 * @format: The format of the output
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list my_vars;
	unsigned int itr, count = 0;

	va_start(my_vars, format);
	for (itr = 0; format[itr] != '\0'; itr++)
	{
		if (format[itr] == '%')
		{
			if (format[itr + 1] == 'b')
				count += int_bin(va_arg(my_vars, int));
			if (format[itr + 1] == 'c')
			{
				_putchar(va_arg(my_vars, int));
				count++;
			}

		if (format[itr + 1] == 'd')
			count += print_int(va_arg(my_vars, int));
		if (format[itr + 1] == 'i')
			count += print_inti(va_arg(my_vars, int));
		if (format[itr + 1] == 's')
			count += print_string(va_arg(my_vars, const char*));

		if (format[itr + 1] == '%')
		{
			_putchar('%');
			count++;
		}
		itr++;
		}
		else
		{
		_putchar(format[itr]);
		count++;
		}
	}
	va_end(my_vars);
	return (count);
}
