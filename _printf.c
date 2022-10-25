#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * find_correct_func - finding the format for _printf
 * @format: format
 * Return: NULL
 */

int (*find_correct_func(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{"r", print_rev},
		{"b", print_bin},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"R", print_rot13},
		{"S", print_S},
		{"p", print_p},
		{NULL, NULL}
	};

	while (find_f[i].sc)
	{
		if (find_f[i].sc[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _printf - produces an output based on format
 * @format: format
 * Return: size
 */
int _printf(const char *format, ...)
{
	va_list parameter_list;
	int n;

	va_start(parameter_list, format);
	n = vfprintf(stdout, format, parameter_list);
	va_end(parameter_list);
	return (n);
}
