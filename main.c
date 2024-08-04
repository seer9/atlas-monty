#include "monty.h"

char *push_arg; /* global variable to store the push argument */
/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 on failure
 */
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

		if (opcode && opcode[0] != '#')  /* Ignore empty lines and comments */
		{
			exe_instruction(opcode, arg, &stack, line_number);
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);  /* Ensure stack is freed properly */
	return (0);
}
/**
 * free_stack - Frees the memory allocated for the stack
 * @stack: Pointer to the stack
 */
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
