#include <string.h>

/**
  * _strlen - returns the length of a string
  * @s: string whose length is to be found.
  *
  * Return: returns the length of the @s
  */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	i++;
	return (i);
}
