#include "monty.h"

/**
 * is_integer - checks if a string represents a valid integer
 * @str: the string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * val_int - checks if a string represents a valid integer
 *
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
			return (0);
		str++;
	}
	return (1);
}
