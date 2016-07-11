#include "header.h"

/*
 * main() - Create a hash table of size 3, put keyed item in the hashtable,
 * call printf to print the value of the key. Free the hash before returning.
 *
 * Return: 0 upon success, 1 upon failure.
 */
int main(void) {
        HashTable *ht;

        ht = ht_create(1);
        if (ht == NULL) {
                return 1;
        }

        if (ht_put(ht, "isFun", "C") == 0) {
                printf("%s\n", ht_get(ht, "isFun"));
                ht_free(ht);
                return 0;
        }

        return 1;
}
