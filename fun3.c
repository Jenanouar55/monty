#include "monty.h"
/**
 * fpstr - Prints the ASCII values of the stack until non-printable character.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void fpstr(stack_t **stack, unsigned int line_number)
{
	stack_t *x = *stack;
	int y = 0;

	(void)line_number;
	while (x)
	{
		y = x->n;
		if (y == 0 || _isalpha(y) == 0)
			break;
		putchar(y);
		x = x->next;
	}
	putchar('\n');
}
/**
 * frotl - Rotates the stack to the left.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void frotl(stack_t **stack, unsigned int line_number)
{
	stack_t *z = *stack;
	int w = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;
	w = z->n;

	while (z->next)
	{
		z = z->next;
		z->prev->n = z->n;
	}

	z->n = w;
}
/**
 * frotr - Rotates the stack to the right.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void frotr(stack_t **stack, unsigned int line_number)
{
	stack_t *x = *stack;
	int y = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;
	while (x->next)
		x = x->next;
	y = x->n;
	while (x->prev)
	{
		x = x->prev;
		x->next->n = x->n;
	}
	x->n = y;
}
