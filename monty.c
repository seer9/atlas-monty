#include "monty.h"

/**
 * main - Entry point for monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    char *opcode, *arg;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \n\t");
        arg = strtok(NULL, " \n\t");

        if (opcode == NULL || opcode[0] == '#')
            continue;

        execute_instruction(opcode, arg, &stack, line_number);
    }

    free(line);
    fclose(file);
    return (0);
}

/**
 * exe_instruction - Executes the instruction

 * @opcode: The opcode
 * @arg: The argument
 * @stack: Pointer to the stack
 * @line_number: The line number
 */

void exe_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    int i;
    instruction_t instructions[] = {
        {"push", (void (*)(stack_t **, unsigned int))push},
        {"pall", pall},
        {NULL, NULL}
    };

    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
