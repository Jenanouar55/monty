#include "monty.h"
#include <stdio.h>

/**
 * f_pall - Print all values on the stack
 * @head: Pointer to the head of the stack
 * @c: Line number being executed
 *
 * Description: This function prints all the values on the stack,
 * starting from the top.
 */
void f_pall(stack_t **head, unsigned int c)
{
	stack_t *i;
	(void)c;

	i = *head;

	while (i != NULL)
	{
		printf("%d\n", i->n);
		i = i->next;
	}
}
