#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <stdio.h>

void free_node(NTree *tree);
void free_list(List *list);

void ntree_free(NTree *tree)
{
	if (tree == NULL)
	{
		return;
	}

	free_node(tree);
}

void free_node(NTree *tree)
{
	free_list(tree->children);

	free(tree->str);
	free(tree->children);
	free(tree);
}

void free_list(List *list)
{
	while(list->next != NULL)
	{
		free_node(list->node);
		list = list->next;
	}

	if (list->node != NULL)
	{
		free_node(list->node);
	}
}
