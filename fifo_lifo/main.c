#include "header.h"

int main(int ac, char **av)
{
        Stack *stack;
        int i;
        char *str;

        stack = NULL;
        i = 0;
        while (i < ac)
        {
                push_stack(&stack, av[i]);
                ++i;
        }
        print_stack(stack);
        str = pop_stack(&stack);
        printf("%s\n", str);
        print_stack(stack);
        str = pop_stack(&stack);
        printf("%s\n", str);
        print_stack(stack);
        str = pop_stack(&stack);
        printf("%s\n", str);
        print_stack(stack);
        return (0);
}
