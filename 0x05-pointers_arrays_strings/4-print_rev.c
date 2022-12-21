#include "main.h"

/**
  * print_rev - print a string, in reverse, followed by a new line
  * Return: nothing on success
  */
void print_rev(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	while (i--)
		{
			_putchar(s[i]);
			i--;
		}
	_putchar('\n');
}
