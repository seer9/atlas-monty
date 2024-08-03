#include "monty.h"

char *push_arg; // Declare a global variable to store the push argument

int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \t\n");
        char *arg = strtok(NULL, " \t\n");

        if (opcode && opcode[0] != '#')  // Ignore empty lines and comments
        {
            exe_instruction(opcode, arg, &stack, line_number);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);  // Ensure all stack elements are freed
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