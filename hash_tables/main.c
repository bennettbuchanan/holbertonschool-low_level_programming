#include "header.h"
int print_hashtable(HashTable *ht);

int main(void) {
        HashTable *ht;
        ht = ht_create(3);
        ht_put(ht, "key 1", "val 1");
        ht_put(ht, "key 2", "val 2");
        ht_put(ht, "key 3", "val 3");
        ht_put(ht, "key 4", "val 4");
        ht_put(ht, "key 5", "val 5");
        ht_put(ht, "key 6", "val 6");
        print_hashtable(ht);

        ht_free(ht);
        return 0;
}

int print_hashtable(HashTable *ht) {
        unsigned int i;
        List *listptr;
        for (i = 0; i < ht->size; ++i) {
                printf("%d\n", i);

                listptr = ht->array[i];
                printf("\t--------\n");

                while (listptr != NULL) {
                        printf("\tkey: %s\n\tval: %s\n\t--------\n", listptr->key, listptr->value);
                        listptr = listptr->next;
                }
                printf("\tNULL\n\t--------\n");
        }
        return 0;
}
