#include "monty.h"

/**
 * fswap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void fswap(stack_t **stack, unsigned int line_number)
{
	stack_t *x;
	int tmp;

	x = *stack;
	if (x == NULL || x->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = x->n;
	x->n = x->next->n;
	x->next->n = tmp;
}

/**
 * fadd - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void fadd(stack_t **stack, unsigned int line_number)
{
	stack_t *y = *stack;
	int sum = 0, count = 0;

	if (y == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (y)
	{
		y = y->next;
		count++;
	}
	if (stack == NULL || (*stack)->next == NULL || count <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	fpop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * fnop - Does nothing.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void fnop(__attribute__ ((unused)) stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * fpchar - Prints the ASCII value of the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void fpchar(stack_t **stack, unsigned int line_number)
{
	int z;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	z = (*stack)->n;
	if (z > 127 || z < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	putchar(z);
	putchar('\n');
}

/**
 * _isalpha - Checks if an integer represents an alphabetic character.
 * @c: Integer value to check.
 * Return: 1 if 'c' is an alphabetic character, 0 otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
