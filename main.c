#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    FILE *file;
    char buffer[1024];
    unsigned int line_number = 0;
    char *opcode;
    char *arg;
    int value; /* Declare 'value' here */

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

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
                return EXIT_FAILURE;
	    }
            value = atoi(arg); /* Assign 'value' here */
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        /* Add other opcode cases here */

        /* If the opcode is not recognized, handle the error */
    }

    fclose(file);
    return EXIT_SUCCESS;
}

