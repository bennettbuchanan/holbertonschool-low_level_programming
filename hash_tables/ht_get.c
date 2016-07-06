#include "header.h"

/*
 * ht_get() - Traverse the list that is at the corresponding array location in
 * the hashtable. If a node with the same key is found as that passed to this
 * function, then return the value of that node. Otherwise, return NULL,
 * indicating there is no node with the key passed.
 * @hashtable: The hashtable in which to search for the data.
 * @key: The key to search the hashtable for.
 *
 * Return: The value that corresponds to the key if it is found, and NULL
 * Otherwise.
 */
char *ht_get(HashTable *hashtable, const char *key)
{
        char *key_cp = strdup(key);
        unsigned int i = hash(key, hashtable->size);
        List *tmp = hashtable->array[i];

        while (tmp != NULL) {
                if (str_cmp(tmp->key, key_cp) == 0) {
                        break;
                }
                tmp = tmp->next;
        }

        if (tmp == NULL) {
                return NULL;
        } else {
                return tmp->value;
        }
}
