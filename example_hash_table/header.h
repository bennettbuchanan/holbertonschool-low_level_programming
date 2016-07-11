#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTable *ht_create(unsigned int);
int ht_put(HashTable *, const char *, const char *);
int add_begin_list(List **, List *);
void node_handler(HashTable *, List *);
char *ht_get(HashTable *, const char *);
void ht_free(HashTable *);
void print_str(char *str);
int print_char(char c);
void print_num(int n);
