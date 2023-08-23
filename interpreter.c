#include <string.h>
#include "monty.h"

/**
 * interpret_file - Interprets Monty bytecode from a file.
 * @file: Pointer to the opened file containing Monty bytecode.
 * @stack: Pointer to the stack.
 */
void interpret_file(FILE *file, stack_t **stack)
{
	char buffer[1024];
	unsigned int line_number = 0;
	char *opcode;
	char *arg;
	int value;

	while (fgets(buffer, sizeof(buffer), file))
	{
		line_number++;
		opcode = strtok(buffer, " \t\n");
		if (opcode == NULL)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack);
		}
		/* Handle other opcode cases here */
		/* Handle unrecognized opcodes */
	}
}
