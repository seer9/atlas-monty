#include "monty.h"

/**
 * main - Entry point
 *
 * @argc: Number of arguments
 * @argv: Array of arguments
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
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
        char *opcode = strtok(line, " \n\t\r");
        char *arg = strtok(NULL, " \n\t\r");
        if (opcode == NULL)
            continue;
        
        exe_instruction(opcode, arg, &stack, line_number);
    }
    free(line);
    fclose(file);
    free_stack(stack);
    return (0);
}

void free_stack(stack_t *stack)
{
    stack_t *temp;
    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}