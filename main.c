#include "monty.h"

/**
 * main - Entry point for Monty interpreter
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *monty_file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    monty_file = fopen(argv[1], "r");
    if (monty_file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, monty_file)) != -1)
    {
        line_number++;

        /* Remove newline character if present */
        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';

        /* Parse and execute Monty commands */
        getfunction(&stack, line, line_number);
    }

    /* Close the Monty file */
    fclose(monty_file);

    /* Free dynamically allocated memory */
    if (line)
        free(line);
    free_stack(&stack);

    return (EXIT_SUCCESS);
}
