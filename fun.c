#include "monty.h"

/**
 * fpush - push int to a stack
 * @stack: linked list for Monty stack
 * @line_number: number of line opcode occurs on
 */
void fpush(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
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
 * fpall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void fpall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *y;

	y = *stack;
	while (y != NULL)
	{
		printf("%d\n", y->n);
		y = y->next;
	}
}
/**
 * fpint - Print the integer value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the opcode occurs
 */
void fpint(stack_t **stack, unsigned int line_number)
{
	stack_t *x;

	x = *stack;
	if (x == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", x->n);
}
/**
 * fpop - Remove the top element from the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the opcode occurs
 */
void fpop(stack_t **stack, unsigned int line_number)
{
	stack_t *y = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = y->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(y);
}
/**
 * free_dlistint - Free a doubly linked list
 * @head: Pointer to the head (first node) of the list
 */
void free_dlistint(stack_t *head)
{
	stack_t *w;

	while (head != NULL)
	{
		w = head->next;
		free(head);
		head = w;
	}
}
