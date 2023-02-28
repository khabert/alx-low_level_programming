#include "main.h"
#include <stdio.h>
#include <string.h>

/**
  * _puts - prints a string, followed by a new line, to stdout.
  * @str: string to be printed
  *
  * Return: returns a string
  */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		putchar(str[i]);
		i++;

	}
	putchar('\n');
}
