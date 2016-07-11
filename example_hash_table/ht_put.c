#include "header.h"

/*
 * ht_put() - Allocates memory for a new node and calls the node_handler
 * function to either insert the node if the key does not exist, or update
 * a prexisting node in the case that it has the same key as that passed
 * to this function.
 * @key: The key to add to the hash table.
 * @value: The corresponding value to add to the node.
 *
 * Return: 1 if memory allocation fails, and 0 if the function returns
 * successfully.
 */
int ht_put(HashTable *hashtable, const char *key, const char *value)
{
        List *node;

        if (hashtable == NULL) {
                return 1;
        }

        node = malloc(sizeof(List));
        if (node == NULL) {
                return 1;
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
                        if (strcmp(tmp->key, node->key) == 0) {
                                break;
                        }
                        tmp = tmp->next;
                }
                if (tmp == NULL) {
                        node->next = hashtable->array[i];
                        hashtable->array[i] = node;
                } else {
                        free(tmp->value);
                        tmp->value = strdup(node->value);
                        free(node->value);
                        free(node->key);
                        free(node);
                }
        } else {
                node->next = NULL;
                hashtable->array[i] = node;
        }
}
