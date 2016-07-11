#include "header.h"

/*
 * ht_get() - Traverse the list that is at the corresponding array location in
 * the hashtable. If a node with the same key is found as that passed to this
 * function, then return the value of that node. Otherwise, return NULL,
 * indicating there is no node with the key passed. Before returning, free
 * the copy of the string `key_cp`.
 * @hashtable: The hashtable in which to search for the data.
 * @key: The key to search the hashtable for.
 *
 * Return: The value that corresponds to the key if it is found, and NULL
 * otherwise. If the hashtable is NULL, return NULL.
 */
char *ht_get(HashTable *hashtable, const char *key)
{
        char *key_cp;
        unsigned int i;
        List *tmp;

        if (hashtable == NULL) {
                return NULL;
        }
        key_cp = strdup(key);
        i = hash(key, hashtable->size);
        tmp = hashtable->array[i];

        while (tmp != NULL) {
                if (strcmp(tmp->key, key_cp) == 0) {
                        break;
                }
                tmp = tmp->next;
        }
        free(key_cp);

        if (tmp == NULL) {
                return NULL;
        }
        return tmp->value;
}
