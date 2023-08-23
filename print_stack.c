#include "monty.h"

/**
 * printstack - Prints all elements of the stack
 * @stack: Pointer to the stack
 */
void printstack(stack_t *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

