#include "monty.h"


/**
 * pop - function that pop the top
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *current, *first = *head;

	if (!head)
	{
		dprintf(1, "%s\n", "Head is empty!");
		exit(1);
	}

	(void)line;

	if (!(*head)->next)
		*head = NULL;
	else
	{
		current = first->next;
		current->prev = NULL;
		*head = current;
		free(first);
	}

}

/**
 * push - function that push element to the top
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void push(stack_t **head, unsigned int line)
{
	int n = 0;
	stack_t *new, *current;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(2, "%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->next = NULL;
	new->n = n;

	if (!(*head))
		*head = new;
	else
	{
		current = *head;
		new->next = current;
		current->prev = new;
		*head = new;
	}
}

/**
 * swap - function that top elements
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *current = *head, *temp;

	if (!(current) || !current->next)
		_stdexit("Error: swap failed");

	(void)line;

	temp = current->next;
}