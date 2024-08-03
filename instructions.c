#include "monty.h"
#include <string.h>

void exe_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    int i;

    instruction_t instruct[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };

    for (i = 0; instruct[i].opcode != NULL; i++)
    {
        if (strcmp(instruct[i].opcode, opcode) == 0)
        {
            if (strcmp(opcode, "push") == 0)
            {
                push(stack, line_number, arg);
            }
            else
            {
                instruct[i].f(stack, line_number);
            }
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