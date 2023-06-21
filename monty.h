#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"
extern char **op_toks;
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
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int monty(FILE *);
char **_strtok(char *);
void free_stack(stack_t **);
int create_stack(stack_t **);
void _free(char **);
unsigned int readLine(FILE *, char **);
int (*function_selector(char *))(stack_t**, unsigned int);
/*opcode functions*/
int push(stack_t **, unsigned int);
int pall(stack_t **, unsigned int);
int pint(stack_t **, unsigned int);
int pop(stack_t **, unsigned int);
int swap(stack_t **, unsigned int);
int add(stack_t **, unsigned int);
int nop(stack_t **, unsigned int);
int sub(stack_t **, unsigned int);
int _div(stack_t **, unsigned int);
int mul(stack_t **, unsigned int);
int mod(stack_t **, unsigned int);
int pchar(stack_t **, unsigned int);
int pstr(stack_t **, unsigned int);
int rotl(stack_t **, unsigned int);
int rotr(stack_t **, unsigned int);
int stack(stack_t **, unsigned int);
int queue(stack_t **, unsigned int);
#endif
