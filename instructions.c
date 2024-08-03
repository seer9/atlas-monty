#include "monty.h"
#include <string.h>

/* Define the instruction array named "instruction_set" */
instruction_t instruction_set[] = {
    {"push", push_wrapper},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {NULL, NULL}
};

/**
 * push_wrapper - wrapper function to call push with an additional argument
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * This wrapper function allows push to be used in the instruction_set array.
 */
void push_wrapper(stack_t **stack, unsigned int line_number) {
    extern char *push_arg; // Use a global variable to store the push argument
    push(stack, line_number, push_arg);
}

/**
 * exe_instruction - executes the given opcode
 * @opcode: string representing the opcode
 * @arg: argument for the opcode (if any)
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 */
void exe_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    int i;
    extern char *push_arg; // Use a global variable to store the push argument
    push_arg = arg;

    for (i = 0; instruction_set[i].opcode != NULL; i++)
    {
        if (strcmp(instruction_set[i].opcode, opcode) == 0)
        {
            instruction_set[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

void push(stack_t **stack, unsigned int line_number, char *arg)
{
    int n;
    stack_t *new_node;

    if (!is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    n = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
