#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number in the file
 * @arg: the argument to be pushed
 */
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