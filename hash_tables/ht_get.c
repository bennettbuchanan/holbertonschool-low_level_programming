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
                if (str_cmp1(tmp->key, key_cp) == 0) {
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

/*
 * str_cmp1() - Compare two strings to determine if they are identical. Ensures
 * that each char in the strings are the same, and that they are of the same
 * length.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Zero if the strings are identical, one otherwise.
 */
int str_cmp1(char *s1, char *s2)
{
	int i;
	int j = 0;

        for (i = 0; s1[i] != '\0'; ++i) {
		if (s1[j] != s2[j] || s1[j + 1] != s2[j + 1]) {
			return 1;
		}
		j++;
	}
	return 0;
}
