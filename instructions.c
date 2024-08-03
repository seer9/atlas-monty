#include "monty.h"
#include <string.h>

typedef void (*opcode_func_t)(stack_t **stack, unsigned int line_number, char *arg);

void exe_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    int i;
    char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add", "nop", NULL};
    opcode_func_t functions[] = {
        push,
        (opcode_func_t) pall,
        (opcode_func_t) pint,
        (opcode_func_t) pop,
        (opcode_func_t) swap,
        (opcode_func_t) add,
        (opcode_func_t) nop
    };
    for (i = 0; opcodes[i] != NULL; i++)
    {
        if (strcmp(opcodes[i], opcode) == 0)
        {
            functions[i](stack, line_number, arg);
            return;
        }
    }
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}