/**
  * strlen - returns the length of a string
  * @c: string whose length is to be found.
  *
  * Return: returns the length of the @s
  */
int strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;
	return (count);
}
