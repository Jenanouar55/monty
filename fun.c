#include "monty.h"

/**
 * _push - push int to a stack
 * @stack: linked list for Monty stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *x;
	(void)line_number;

	x = malloc(sizeof(stack_t));
	if (x == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	x->n = var_global.push_arg;
	x->next = *stack;
	x->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = x;
	*stack = x;
}

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *y;

	y = *stack;
	while (y != NULL)
	{
		printf("%d\n", y->n);
		y = y->next;
	}
}
