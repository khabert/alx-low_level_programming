#include <stdio.h>
#include <stdlib.h>

/**
  * main - returns alphabets both lower and upper cases
  *
  * Returns: Always 0 (Success)
  */
int main(void)
{
	int ch = 'a';
	int ch = 'A';
	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	while (CH <= 'Z')
	{
		putchar(CH);
		CH++;
	}

	putchar('\n');
	return (0);
}
