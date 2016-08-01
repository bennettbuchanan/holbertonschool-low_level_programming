#include <stdlib.h>
#include "tree.h"

int ntree_insert(NTree **, char **, char *);

void ntree_print(NTree *);
void ntree_free(NTree *);
char **string_split(const char *, char);
void free_str_array(char **);

int main(void)
{
    NTree *tree;
    char **array;

    tree = NULL;
    ntree_insert(&tree, NULL, "/");

    ntree_insert(&tree, (array = string_split("/", ' ')), "tmp");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ tmp", ' ')), "tmp_file");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ tmp", ' ')), "tmp_file2");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ tmp", ' ')), "tmp_file3");
    free_str_array(array);

    ntree_insert(&tree, (array = string_split("/", ',')), "mnt");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ mnt", ' ')), "HDD1");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ mnt HDD1", ' ')), "Desktop");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ mnt HDD1 Desktop", ' ')), "image.jpg");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ mnt", ' ')), "HDD2");
    free_str_array(array);

    ntree_insert(&tree, (array = string_split("/", ',')), "home");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home", ' ')), "ubuntu");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Documents");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Download");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Public");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Templates");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Pictures");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Videos");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Music");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Desktop");
    free_str_array(array);

    ntree_insert(&tree, (array = string_split("/", ',')), "dev");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ dev", ' ')), "urandom");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sda");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sda1");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sda2");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sdb");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sdb1");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sdb2");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sdb3");
    free_str_array(array);

    ntree_print(tree);
    ntree_free(tree);
    return (0);
}
