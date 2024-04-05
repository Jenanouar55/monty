#include "monty.h"
/**
 * f_push - pushes an element onto the stack
 * @head: pointer to the top of the stack
 * @c: current line number of the opcode in the Monty file
 */
void f_push(stack_t **head, unsigned int c)
{
	int value;

	if (glob.arg == NULL || !is_valid_n(glob.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", c);
		free_stack(*head);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}

	value = atoi(glob.arg);
	addnode(head, value);
}

/**
 * is_valid_n - checks if a string is a valid integer
 * @s: string to check
 *
 * Return: 1 if string is a valid integer, 0 otherwise
 */
int is_valid_n(char *s)
{
	if (s == NULL || *s == '\0')
		return (0);

	if (*s == '-' || *s == '+')
		s++;

	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
