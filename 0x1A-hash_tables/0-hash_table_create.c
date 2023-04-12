#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the hash table
 *
 * Return: A pointer to the newly created hash table, or NULL if it fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_ht = NULL;
	unsigned long int i;

	new_ht = malloc(sizeof(hash_table_t));
	if (!new_ht)
		return (NULL);
	new_ht->size = size;
	new_ht->array = malloc(size * sizeof(hash_node_t *));
	if (!new_ht->array)
		return (NULL);
	for (i = 0; i < size; i++)
		new_ht->array[i] = NULL;
	return (new_ht);
}
