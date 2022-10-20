#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_percent -  print percent character
 * @args: char
 * Return: percent character
 */

int print_percent(va_list args _attribute_((unused)))
{
	return (_putchar('%'));
}
