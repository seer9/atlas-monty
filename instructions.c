#include "monty.h"
/**
 * exe_instruction - Executes the instruction
 *
 * @opcode: The opcode
 * @arg: The argument
 * @stack: Pointer to the stack
 * @line_number: The line number
 */
void exe_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    int i;
    instruction_t instructions[] = {
        {"push", (void (*)(stack_t **, unsigned int)) push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };
    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            if (strcmp(opcode, "push") == 0)
                push(stack, line_number, arg);
            else
                instructions[i].f(stack, line_number);
            return;
        }
    }
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}