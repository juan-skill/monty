#include "monty.h"


/**
 * main - entry point to run monty code
 * @argc: number of arguments of argv
 * @argv: list arguments
 * Return: return (exit success)
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	stack_t *head = NULL;
	char *str = NULL, *command = NULL;
	unsigned int nth_command = 0;
	size_t length = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	handle.file = file;
	handle.type_container = 1;

	/* getline != -1 */
	while (getline(&str, &length, file) != EOF)
	{
		nth_command++;
		handle.input = str;
		if (*str == '\n')
			continue;

		command = strtok(str, "\n\t ");
		if (command == NULL)
			continue;

		handle.arg_num = strtok(NULL, "\n\t ");
		opcode(command, nth_command, &head);
	}
	free_stack(&head);

	return (EXIT_SUCCESS);
}




/**
 * opcode - check for operation code
 * @command: cammand input
 * @line_num: line number
 * @head: pointer to the stack
 */
void opcode(char *command, unsigned int line_num, stack_t **head)
{
	int i;
	instruction_t ops[] = {
		{"push", push},	{"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {NULL, NULL}
	};

	if (strpbrk(command, "#"))
		return;

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, command) == 0)
		{
			ops[i].f(head, line_num);/* ops[i].push(head, n_lin)*/
			return;/* ops[i].pall(head, n_lin)*/
		}
	}
	printf("L%d: unknown instruction %s\n", line_num, command);

	free_stack(head);
	exit(EXIT_FAILURE);
}
