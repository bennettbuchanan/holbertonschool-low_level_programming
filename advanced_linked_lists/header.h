#include "list.h"
#include <string.h>
#include <stdlib.h>

int print_char(char);
int print_char(char);
void print_string(char *);
void print_str(char *);
int add_end_dl_list(List **, char *);
int add_begin_dl_list(List **, char *);
void print_dl_list(List *);
List *array_to_dl_list(char **);
void print_prev(List *);
void print_next(List *);
void free_dl_list(List *);
int add_end_cl_list(List **, char *);
int add_begin_cl_list(List **, char *);
void free_cl_list(List *);
int add_end_dcl_list(List **, char *);
int add_begin_dcl_list(List **, char *);
List *array_to_dcl_list(char **);
void free_dcl_list(List *);
