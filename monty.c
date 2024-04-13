#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>
/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	ssize_t read;

	var_global.file = fopen(filename, "r");
	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parse_line(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_op_func - checks opcode and returns the correct function
 * @str: the opcode
 * Return: returns a function, or NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int x;

	instruction_t u[] = {
		{"push", fpush},
		{"pall", fpall},
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"add", fadd},
		{"nop", fnop},
		{"sub", fsub},
		{"mul", fmul},
		{"div", fdiv},
		{"mod", _mod},
		{"pchar", fpchar},
		{"pstr", fpstr},
		{"rotl", frotl},
		{"rotr", frotr},
		{NULL, NULL},
	};
	x = 0;
	while (u[x].f != NULL && strcmp(u[x].opcode, str) != 0)
	{
		x++;
	}
	return (u[x].f);
}

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int x;

	if (str == NULL)
		return (0);
	x = 0;
	while (str[x])
	{
		if (str[0] == '-')
		{
			x++;
			continue;
		}
		if (!isdigit(str[x]))
			return (0);
		x++;
	}
	return (1);
}

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @y: pointer to the head of the stack
 * @z: the current line number
 * Return: returns the opcode or NULL on failure
 */
char *parse_line(char *line, stack_t **y, unsigned int z)
{
	char *v, *push, *arg;
	(void)y;

	push = "push";
	v = strtok(line, "\n ");
	if (v == NULL)
		return (NULL);
	if (strcmp(v, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", z);
			exit(EXIT_FAILURE);
		}
	}
	return (v);
}
