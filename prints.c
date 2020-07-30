#include "monty.h"

/**
 * pall - print out all the stack
 * @head: pointer to the stack
 * @line_num: line number
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = NULL;

	(void)line_num;

	if (head == NULL || *head == NULL)
		return;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print the top of the stack
 * @head: pointer to the stack
 * @line_num: line number
 */
void pint(stack_t **head, unsigned int line_num)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
