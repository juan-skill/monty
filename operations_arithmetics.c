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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->next;
	tmp->n += (*head)->n;
	free(*head);
	*head = tmp;
}


/**
 * sub - subtractting first two elements
 *
 * @head: input stack address
 * @line_num: current line number
 * Return: void
 */
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->next;
	tmp->n -= (*head)->n;
	pop(head, line_num);
	(*head) = tmp;
	tmp = NULL;

}



/**
 * _div - subtractting first two elements
 *
 * @head: input stack address
 * @line_num: current line number
 * Return: void
 */
void _div(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->next;

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	tmp->n /= (*head)->n;
	pop(head, line_num);
	(*head) = tmp;
	tmp = NULL;
}
