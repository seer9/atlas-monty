#include "monty.h"

/**
 * exe_instruction - executes the given opcode
 * @opcode: string representing the opcode
 * @arg: argument for the opcode (if any)
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 */
void exe_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    if (strcmp(opcode, "push") == 0)
    {
        push(stack, line_number, arg);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(stack, line_number);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
        swap(stack, line_number);
    }
    else if (strcmp(opcode, "add") == 0)
    {
        add(stack, line_number);
    }
    else if (strcmp(opcode, "nop") == 0)
    {
        nop(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}