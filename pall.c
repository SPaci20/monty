#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the stack's top node
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
