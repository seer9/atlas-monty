#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}
