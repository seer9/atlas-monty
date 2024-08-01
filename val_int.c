#include "monty.h"

/**
 * is_integer - checks if a string represents a valid integer
 * @str: the string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int val_int(const char *str)
{
    if (str == NULL || *str == '\0')
        return (0);

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return (1);
}

/**
 * push - pushes an element to the stack
 * 
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number in the file
 * @arg: the argument to be pushed
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    int n;
    stack_t *new_node;

    if (!val_int(arg))
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

/**
 * pall - prints all the values on the stack, starting from the top
 * 
 * @stack: pointer to the head of the stack
 */
void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}