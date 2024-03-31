#include "monty.h"

/**
 * f_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * @counter: line count
 *
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int counter)
{
	int index = 0;
	int is_negative = 0;
	int flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			is_negative = 1;

		for (index = is_negative; bus.arg[index] != '\0'; index++)
		{
			if (!isdigit(bus.arg[index]))
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	int value = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, value);
	else
		addqueue(head, value);
}
