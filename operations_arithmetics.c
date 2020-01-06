#include "monty.h"

/**
 * add - adding first two elements
 * @head: input stack address
 * @line_num: current line number
 */
void add(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->next;
	tmp->n += (*head)->n;
	free(*head);
	*head = tmp;
}
