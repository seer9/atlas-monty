#include "monty.h"
#include <string.h>

/* Global variable for push argument */
char *push_arg;


/* Define the instruction array named "instruct" */
instruction_t instruct[] = {
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
void exe_instruction(char *opcode, char *arg, stack_t **stack,
unsigned int line_number)
{
	int i;

	push_arg = arg;

	for (i = 0; instruct[i].opcode != NULL; i++)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
		{
			instruct[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * push_wrapper - wrapper function to call push with an additional argument
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 */
void push_wrapper(stack_t **stack, unsigned int line_number)
{
	push(stack, line_number, push_arg);
}
