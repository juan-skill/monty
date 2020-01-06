#include "monty.h"


/**
 * add_node - push or enqueue an element at the beginning
 * @head: pointer to the stack
 * @n: value of the node add
 * Return: pointer new node or NULL
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);


	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * free_stack - free the stack and the str input
 * @head: input list pointer
 */
void free_stack(stack_t **head)
{
	stack_t *current;

	if (head == NULL)
		return;

	free(handle.input);
	fclose(handle.file);

	while (*head != NULL)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
}




/**
 * pop_alter - return the node at the beginning of stack
 * @head: pointer to the stack
 * Return: pointer the node or NULL
 */
stack_t *pop_alter(stack_t **head)
{
	stack_t *tmp;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;

	return (tmp);
}



/**
 * add_node_end - add node at the end of stack
 * @head: pointer to a stack
 * @n: value of the node
 * Return: address of node or NULL
 */
stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new, *tmp;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head)
	{
		for (tmp = *head; tmp->next;)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}

	return (new);
}
