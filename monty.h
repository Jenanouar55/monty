#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global variable*/
typedef struct global_s{
	char *arg;
	FILE *file;
	char *line;
} glob_t;
extern glob_t glob;

/* Function prototypes */
void f_push(stack_t **head, unsigned int c);
void f_pall(stack_t **head, unsigned int c);
void free_stack(stack_t *head);
void addnode(stack_t **head, int value);
void addqueue(stack_t **head, int value);

/* Stack helper functions */
int is_valid_n(char *s);
#endif /* MONTY_H */

