#include <stdlib.h>
#include "list.h"

char *str_copy(char *, int);

int add_node(List **list, char *str)
{
        List *node;
        int len;

        node = malloc(sizeof(List));
        if (node == NULL) {
                return 1;
        }

        for(len = 0; str[len] != '\0'; ++len);

        node->str = str_copy(str, len);
        node->next = *list;

        *list = node;

        return 0;
}

char *str_copy(char *src, int len)
{
        int i;
        char *dest;

        /* Allocate the same amount of memory as the original string. */
        dest = malloc(sizeof(char) * (len + 1));
        if (dest == NULL) {
                return NULL;
        }

        /* Copy the string. */
        for(i = 0; i < len + 1; ++i){
                dest[i] = src[i];
        }

        return dest;
}
