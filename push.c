#include "monty.h"


/**
 * push - push integers to the stack
 * @head: pointer to the stack
 * @nth_command: line number
 */
void push(stack_t **head, unsigned int nth_command)
{
	stack_t *node = NULL;
	char *str = handle.arg_num;

	if (head == NULL)
		exit(EXIT_FAILURE);

	if (isnum(str) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", nth_command);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	if (handle.type_container)
		node = add_node(head, atoi(handle.arg_num));
	else
		node = add_node_end(head, atoi(handle.arg_num));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}

}


/**
 * pop - pop the node from memory
 * @head: head of the memory
 * @nth_command: line number
 */
void pop(stack_t **head, unsigned int nth_command)
{
	stack_t *node = NULL;

	node = pop_alter(head);

	if (node == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", nth_command);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	free(node);
}
