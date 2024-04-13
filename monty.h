#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/
extern int push_arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

/*Funtions Monty*/
void fpall(stack_t **stack, unsigned int line_number);
void fpush(stack_t **stack, unsigned int line_number);
void fpint(stack_t **stack, unsigned int line_number);
void fpop(stack_t **stack, unsigned int line_number);
void fswap(stack_t **stack, unsigned int line_number);
void fnop(stack_t **stack, unsigned int line_number);
void frotl(stack_t **stack, unsigned int line_number);
void frotr(stack_t **stack, unsigned int line_number);

/*Functions string ascci */
void fpchar(stack_t **stack, unsigned int line_number);
void fpstr(stack_t **stack, unsigned int line_number);

/*Functions math*/
void fsub(stack_t **stack, unsigned int line_number);
void fadd(stack_t **stack, unsigned int line_number);
void fmul(stack_t **stack, unsigned int line_number);
void fdiv(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/*Utility functions*/
void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);
#endif /* MONTY.H */
