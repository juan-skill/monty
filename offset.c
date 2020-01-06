#include "monty.h"

/**
 * swap - swap top 2 numbers
 * @head: input stack address
 * @line_num: current line number
 */
void swap(stack_t **head, unsigned int line_num)
{
	int n_value = 0;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	n_value = (*head)->n;

	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = n_value;
}
