#include "main.h"

/**
 *_printf - produces output according to a format
 *@format: The output
 *
 *Return: On success 1.
 *On error, -1 is returned, and errno is set appropriately.
 */

int _printf(const char *format, ...)
{
	int charct_num = 0;
	va_list argmnt;

	if (format == NULL)
		return (-1);

	va_start(argmnt, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			charct_num++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				_putchar(*format);
				charct_num++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(argmnt, int);

				_putchar(c);
				charct_num++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(argmnt, char *);
				int len = 0;

				while (str[len] != '\0')
					len++;

				write(1, str, len);

				charct_num += len;
			}
		}

		format++;
	}

	va_end(argmnt);
	return (charct_num);
}
