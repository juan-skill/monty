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


/**
 * pstr - prints the string starting at the top of the stack
 *
 * @head: pointer to the stack
 * @num_line: number of line
 * Description: The string stops when either:
 * the stack is over
 * the value of the element is 0
 * the value of the element is not in the ascii table
 * If the stack is empty, print only a new line
 *
 * Return: void
 */
void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	(void) line_num;

	if (head != NULL)
	{
		tmp = (*head);
		while (tmp != NULL && tmp->n > 0 && tmp->n < 127)
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
	}

	putchar('\n');
}
