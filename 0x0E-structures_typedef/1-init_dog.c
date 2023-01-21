#include "dog.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
  * int_dog - initializes a variable of type struct dog.
  * @d: The dog to be initialized.
  * @name: The name of the dog.
  * @age: The age of the dog.
  * @owner: The owner of the dog.
  * Descriotion: Initializing struct dog
  * Return: 0.
  */
void init_dog(struct dog *d, char *name, float age, char *owner)

{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}