#include "monty.h"

/**
 * fsub - sub top of stack y second top stack
 * @x: pointer to lists for monty stack
 * @y: number of line opcode occurs on
 */
void fsub(stack_t **x, unsigned int y)
{
	stack_t *w = *x;
	int z = 0, i = 0;

	if (w == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", y);
		exit(EXIT_FAILURE);
	}
	while (w)
	{
		w = w->next;
		i++;
	}
	if (x == NULL || (*x)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", y);
		exit(EXIT_FAILURE);
	}
	z = (*x)->next->n - (*x)->n;
	fpop(x, y);
	(*x)->n = z;
}

/**
 * fmul - mul top of stack y second top stack
 * @x: pointer to lists for monty stack
 * @y: number of line opcode occurs on
 */
void fmul(stack_t **x, unsigned int y)
{
	int w;

	if (*x == NULL || (*x)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", y);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*x);
		exit(EXIT_FAILURE);
	}
	else
	{
		w = (*x)->n;
		fpop(x, y);
		(*x)->n *= w;
	}
}
/**
 * fdiv - div top of stack y second top stack
 * @x: pointer to lists for monty stack
 * @y: number of line opcode occurs on
 */
void fdiv(stack_t **x, unsigned int y)
{
	int z = 0;

	if (*x == NULL || (*x)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", y);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*x);
		exit(EXIT_FAILURE);
	}
	else if ((*x)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", y);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*x);
		exit(EXIT_FAILURE);
	}
	else
	{
		z = (*x)->n;
		fpop(x, y);
		(*x)->n /= z;
	}
}

/**
 * _mod - mod top of stack y second top stack
 * @x: pointer to lists for monty stack
 * @y: number of line opcode occurs on
 */
void _mod(stack_t **x, unsigned int y)
{
	int z = 0;

	if (*x == NULL || (*x)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", y);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*x);
		exit(EXIT_FAILURE);
	}
	else if ((*x)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", y);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*x);
		exit(EXIT_FAILURE);
	}
	else
	{
		z = (*x)->n;
		fpop(x, y);
		(*x)->n %= z;
	}
}
