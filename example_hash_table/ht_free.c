#include "header.h"

/*
 * ht_free() - Free the items in a hashtable. Iterate through the hashtable's
 * array. If it is a linked list, then traverse the list and free all the
 * node's attributes and then the node itself. When the end of the list is
 * reached, free the array item itself (i.e., `hashtable->array[i]`). Finally,
 * when all the array items are freed, free the hashtable array pointer and
 * the hashtable itself.
 * @hashtable: The hashtable to free.
 *
 * Return: If the hashtable is NULL, return because there is nothing to free.
 */
void ht_free(HashTable *hashtable)
{
        List *tmp;
        unsigned int i;

        if (hashtable == NULL) {
                return;
        }

        for (i = 0; i < hashtable->size; ++i) {
                if (hashtable->array[i] != NULL) {
                        /* Traverse the list and free the nodes. */
                        while(hashtable->array[i] != NULL) {
                          tmp = hashtable->array[i]->next;
                          free(hashtable->array[i]->key);
                          free(hashtable->array[i]->value);
                          free(hashtable->array[i]);
                          hashtable->array[i] = tmp;
                        }
                        free(hashtable->array[i]);
                }
        }
        free(hashtable->array);
        free(hashtable);
}
