#include "monty.h"
#include <string.h>

/* Global variable for push argument */
char *push_arg; // Ensure this is declared once at top-level file scope

/**
 * push_wrapper - wrapper function to call push with an additional argument
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * This wrapper function allows push to be used in the instruction_set array.
 */
void push_wrapper(stack_t **stack, unsigned int line_number) {
    push(stack, line_number, push_arg);
}

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
 * exe_instruction - executes the given opcode
 * @opcode: string representing the opcode
 * @arg: argument for the opcode (if any)
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 */
void exe_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    int i;
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