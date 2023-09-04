#include "monty.h"

/**
 * pint - function that prints the top
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void pint(stack_t **head, unsigned int line)
{
	if (!head)
	{
		dprintf(1, "%s\n", "Head is empty!");
		exit(1);
	}

	(void)line;

	dprintf(1, "%d\n", (*head)->n);
}

/**
 * pall - function that prints all elements in a stack
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void pall(stack_t **head, unsigned int line)
{
	(void)line;

	while (!*head)
	{
		dprintf(1, "%d\n", (*head)->n);
		*head = (*head)->next;
	}
}

/**
 * _errexit - function that stderr a message
 *
 * @msg: char pointer
 * Return: void
 */
void _errexit(char *msg)
{
	dprintf(2, "%s\n", msg);
	exit(EXIT_FAILURE);
}

/**
 * _stdexit - function that stderr a message
 *
 * @msg: char pointer
 * Return: void
 */
void _stdexit(char *msg)
{
	dprintf(1, "%s\n", msg);
	exit(EXIT_FAILURE);
}

