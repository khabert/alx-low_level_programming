#include "main.h"

/**
  * _putchar - prints a string, followed by a new line, to stdout.
  * @str: string to be printed
  *
  *Return: nothing on success
  */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;

	}
	_putchar('\n');
}
