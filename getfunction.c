#include "monty.h"

/**
 * getfunction - Executes the appropriate opcode function
 * @stack: Pointer to the stack
 * @cmd: Opcode command
 * @lncnt: Line number in the Monty file
 */
void getfunction(stack_t **stack, char *cmd, unsigned int lncnt)
{
    instruction_t opcodes[] = OPCODES;
    int i = 0;

    while (opcodes[i].opcode != NULL)
    {
        if (strcmp(opcodes[i].opcode, cmd) == 0)
        {
            opcodes[i].f(stack, lncnt);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", lncnt, cmd);
    exit(EXIT_FAILURE);
}

