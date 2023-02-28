#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
  * print_rev - print a string, in reverse, followed by a new line
  * @s: string to be printed
  * Return: nothing on success
  */
void print_rev(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	for (s--)
	{
		putchar(s[i]);
		i--;
	}
	putchar('\n');
}
