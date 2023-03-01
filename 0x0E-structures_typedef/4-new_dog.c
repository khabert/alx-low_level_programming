#include "dog.h"
#include <stdlib.h>

int _strien(char *str);
char *_strcopy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);

/**
  * _strlen - Finds the length of a string.
  * @str: The string to be measured.
  * Return: The length of the string.
  */

int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;
	return (len);
}
/**
  * _strcopy - copies a string pointed to by src, including the terminating null
  * byte, to a buffer poited to by dest.
