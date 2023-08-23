#include "monty.h"

/**
 * is_number - Checks if a string is a number
 * @str: String to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *str)
{
	int i = 0;
    if (str == NULL || *str == '\0')
        return 0;

    if (str[0] == '-')
        i = 1;

    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }

    return 1;
}

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    char *token;

    token = strtok(NULL, " \t\n");
    if (token == NULL || !is_number(token))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(token);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

