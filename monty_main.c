#include "monty.h"
global_var var_global;

/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
 */

int main(int argc, char **argv)
{
	stack_t *myStack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &myStack);

	free_dlistint(myStack);
	return (0);
}
