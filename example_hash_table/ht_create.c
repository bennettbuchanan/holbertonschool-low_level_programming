#include "header.h"

/*
 * ht_create() - If the size is a positive integer, allocate the requisite
 * memory for a new hashtable and its indexed array. Assign the size of the
 * array in ht->size.
 * size: The size of the hashtable's array.
 *
 * Return: A pointer to the newly allocated Hashtable. If size is zero or a
 * negative number, return NULL. If a memory allocation fails, return NULL.
 */
HashTable *ht_create(unsigned int size)
{
        HashTable *ht;

        if (size < 1) {
                return NULL;
        }

        ht = malloc(sizeof(HashTable));
        if (ht == NULL) {
                return (NULL);
        }

        ht->array = (List**)malloc(size * sizeof(List));
        if (ht->array == NULL) {
                return (NULL);
        }

        memset(ht->array, 0, size * sizeof(List));

        ht->size = size;

        return ht;
}
