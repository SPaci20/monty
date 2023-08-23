#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 * Return: EXIT_SUCCESS if successful, otherwise EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	interpret_file(file, &stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
