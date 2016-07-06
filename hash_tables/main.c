#include "header.h"
int print_hashtable(HashTable *ht);

int main(void) {
        HashTable *ht;
        ht = ht_create(3);

        if (ht == NULL) {
                return 1;
        }

        ht_put(ht, "key 1", "val 1");
        ht_put(ht, "key 2", "val 2");
        ht_put(ht, "key 3", "val 3");
        ht_put(ht, "key 4", "val 4");
        ht_put(ht, "key 5", "val 5");
        ht_put(ht, "key 4", "NEW VAL 4");
        print_hashtable(ht);
        print_str(ht_get(ht, "key 4"));
        print_str("\n");
        ht_free(ht);
        return 0;
}

int print_hashtable(HashTable *ht) {
        unsigned int i;
        List *listptr;
        for (i = 0; i < ht->size; ++i) {
                print_num(i);
                print_str("\n");

                listptr = ht->array[i];
                print_str("\t--------\n");

                while (listptr != NULL) {
                        print_str("\tkey: ");
                        print_str(listptr->key);
                        print_str("\n\tval: ");
                        print_str(listptr->value);
                        listptr = listptr->next;
                        print_str("\n\t--------\n");
                }
                print_str("\tNULL\n\t--------\n");
        }
        return 0;
}

/*
 * print_str() - Prints a string to stdout.
 * @str: A pointer to a string to be printed.
 *
 * Return: Void.
 */
void print_str(char *str)
{
        int i;
        for(i = 0; str[i] != '\0'; ++i) {
                print_char(str[i]);
        }
}

/*
 * print_num() - Prints a number to stdout.
 * @n: The number to print.
 *
 * Return: Void.
 */
void print_num(int n)
{
        if (n >= 10) {
                print_num(n / 10);
        }
        print_char(n % 10 + 48);
}
