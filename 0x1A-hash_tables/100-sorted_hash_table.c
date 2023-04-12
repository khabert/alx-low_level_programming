#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the hash table
 *
 * Return: a pointer to the created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return NULL;
	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (!ht->array)
		return NULL;
	ht->shead = NULL;
	ht->stail = NULL;
	return ht;
}

/**
 * shash_table_set - adds an element to a sorted hash table
 * @ht: the hash table to add the element to
 * @key: the key of the element to add
 * @value: the value of the element to add
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current_node;

	if (!ht || !key || strcmp(key, "") == 0)
		return 0;

	index = hash_djb2((unsigned char *)key) % ht->size;
	current_node = ht->array[index];

	while (current_node)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			free(current_node->value);
			current_node->value = strdup(value);
			return 1;
		}
		current_node = current_node->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return 0;

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->sprev = NULL;
	new_node->snext = NULL;

	if (!ht->shead)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		current_node = ht->shead;
		while (current_node && strcmp(current_node->key, key) < 0)
			current_node = current_node->snext;

		if (current_node == ht->shead)
		{
			new_node->snext = ht->shead;
			ht->shead->sprev = new_node;
			ht->shead = new_node;
		}
		else if (!current_node)
		{
			new_node->sprev = ht->stail;
			ht->stail->snext = new_node;
			ht->stail = new_node;
		}
		else
		{
			new_node->sprev = current_node->sprev;
			new_node->snext = current_node;
			current_node->sprev->snext = new_node;
			current_node->sprev = new_node;
		}
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
/**
 * shash_table_get - retrieves the value associated with a key in a sorted hash table
 * @ht: the hash table to retrieve the element from
 * @key: the key of the element to retrieve
 *
 * Return: a pointer to the value associated with the key, or NULL if the key was not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;

	if (!ht || !key || !(*key))
		return (NULL);

	node = ht->array[key_index((const unsigned char *)key, ht->size)];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a hash table.
 * @ht: hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;
	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse.
 * @ht: hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;
	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table.
 * @ht: hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;
	unsigned long int i;

	if (!ht)
		return;
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			tmp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = tmp;
		}
	}
	free(ht->array);
	free(ht);
}
