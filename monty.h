#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"
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
	int (*f)(char **op_toks, stack_t **stack, unsigned int line_number);
} instruction_t;
int monty(FILE *);
char **_strtok(char *);
void free_stack(stack_t **);
int create_stack(stack_t **);
void _free(char **);
unsigned int readLine(FILE *, char **);
int (*function_selector(char *))(char **, stack_t**, unsigned int);
/*opcode functions*/
int push(char **, stack_t **, unsigned int);
int pall(char **, stack_t **, unsigned int);
int pint(char **, stack_t **, unsigned int);
int pop(char **, stack_t **, unsigned int);
int swap(char **, stack_t **, unsigned int);
int add(char **, stack_t **, unsigned int);
int nop(char **, stack_t **, unsigned int);
int sub(char **, stack_t **, unsigned int);
int _div(char **, stack_t **, unsigned int);
int mul(char **, stack_t **, unsigned int);
int mod(char **, stack_t **, unsigned int);
int pchar(char **, stack_t **, unsigned int);
int pstr(char **, stack_t **, unsigned int);
int rotl(char **, stack_t **, unsigned int);
int rotr(char **, stack_t **, unsigned int);
int stack(char **, stack_t **, unsigned int);
int queue(char **, stack_t **, unsigned int);
#endif
