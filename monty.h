#ifndef MONTY
#define MONTY

/* libraries  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/* structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct var_glo - handle global variable
 * @file: file descripter input file
 * @arg_num: numerical arguments
 * @input: input string
 * @type_container: checks if it's a stack or queue
 */
typedef struct var_glo
{
	FILE *file;
	char *arg_num;
	char *input;
	int type_container;

} global;

global handle;


/*basic functions related to doubly linked list*/
stack_t *add_node(stack_t **head, const int n);
void free_stack(stack_t **head);
stack_t *pop_alter(stack_t **head);
stack_t *add_node_end(stack_t **head, int n);


/* push and pop  */
void push(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);


/* print */
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);


/* operation mathematics */
void add(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);

void swap(stack_t **stack, unsigned int line_num);

void nop(stack_t **stack, unsigned int line_num);

/* char and string */
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);

/* other functions */
int isnum(char *number);
void opcode(char *command, unsigned int line_num, stack_t **stack);

#endif
