#include "header.h"

/*
 * ht_create() - Allocate the requisite memory for a new hashtable and its
 * indexed array. Assign the size of the array in ht->size.
 * size: The size of the hashtable's array.
 *
 * Return: A pointer to the newly allocated Hashtable.
 */
HashTable *ht_create(unsigned int size)
{
        HashTable *ht;

        ht = malloc(sizeof(HashTable));
        if (ht == NULL) {
                return (NULL);
        }

        ht->array = (List**)malloc(size * sizeof(List));
        if (ht->array == NULL) {
                return (NULL);
        }

        ht->size = size;

        return ht;
}
