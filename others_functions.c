#include "monty.h"

/**
 * isnum - check if string is a number
 * @str: string input
 * Return: 0 if false 1 if true
 */
int isnum(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);

}
