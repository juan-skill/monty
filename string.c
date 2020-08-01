#include "monty.h"


/**
 * pchar - prints the char at the top of stack
 *
 * @head: pointer to the stack
 * @num_line: number of line
 * Return: void
 */
void pchar(stack_t **head, unsigned int line_num)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	if (!(isascii((*head)->n)))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*head)->n);
}
