#include "header.h"

/*
 * ht_put() - Allocates memory for a new node and calls the node_handler
 * function to either insert the node if the key does not exist, or update
 * a prexisting node in the case that it has the same key as that passed
 * to this function.
 * @key: The key to add to the hash table.
 * @value: The corresponding value to add to the node.
 *
 * Return: One if memory allocation fails, and zero if the function returns
 * successfully.
 */
int ht_put(HashTable *hashtable, const char *key, const char *value)
{
        List *node;

        node = malloc(sizeof(List));
        if (node == NULL) {
                return (1);
        }

        node->key = strdup(key);
        node->value = strdup(value);
        node_handler(hashtable, node);

        return 0;
}
/*
 * node_handler() - If the index item is a linked list, traverse it to ensure
 * that there is not already an item with the key passed. If there is,
 * reassign the value of the prexisting node to the current instead of adding
 * the new node.
 * @hashtable: The hashtable of Lists.
 * @node: The linked list to add a node to or update.
 *
 * Return: Void.
 */
void node_handler(HashTable *hashtable, List *node)
{
        unsigned int i = hash(node->key, hashtable->size);
        List *tmp = hashtable->array[i];

        if (hashtable->array[i] != NULL) {
                tmp = hashtable->array[i];
                while (tmp != NULL) {
                        if (str_cmp(tmp->key, node->key) == 0) {
                                break;
                        }
                        tmp = tmp->next;
                }
                if (tmp == NULL) {
                        node->next = hashtable->array[i];
                        hashtable->array[i] = node;
                } else {
                        tmp->value = node->value;
                }
        } else {
                node->next = NULL;
                hashtable->array[i] = node;
        }
}

/*
 * str_cmp() - Compare two strings to determine if they are identical. Ensures
 * that each char in the strings are the same, and that they are of the same
 * length.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Zero if the strings are identical, one otherwise.
 */
int str_cmp(char *s1, char *s2)
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
