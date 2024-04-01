#include "monty.h"
#include <stdio.h>

/**
 * f_pall - Print all values on the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number being executed
 *
 * Description: This function prints all the values on the stack,
 * starting from the top.
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *c; 
	(void)counter;

	c = *head;

	while (c != NULL)
	{
		printf("%d\n", c->n);
		c = c->next;
	}
}
