#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the stack's top node
 * @line_number: Current line number in the Monty bytecode file
 *
 * Return: None
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
