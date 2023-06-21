#include "monty.h"
/**
 * nop - nop
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int nop(char **op_toks, stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	(void)op_toks;
	return (EXIT_SUCCESS);
}
/**
 * pchar - pchar
 * @op_toks: tokens
 * @stack: stack
 * @number: integer
 * Return: success
 */
int pchar(char **op_toks, stack_t **stack, unsigned int number)
{
	(void)op_toks;
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", number);
		return (EXIT_FAILURE);
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", number);
		return (EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->next->n);
	return (EXIT_SUCCESS);
}
/**
 * pstr - pstr
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pstr(char **op_toks, stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	(void)line_number;
	(void)op_toks;
	while (tmp && tmp->n != 0)
	{
		printf("%c", (char)tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
/**
 * stack - stack
 * @op_toks: tokens
 * @stack: stack
 * @number: integer
 * Return: success
 */
int stack(char **op_toks, stack_t **stack, unsigned int number)
{
	(void)number;
	(void)op_toks;
	(*stack)->n = STACK;
	return (EXIT_SUCCESS);
}
/**
 * queue - change stack to queue
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int queue(char **op_toks, stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)op_toks;
	(*stack)->n = QUEUE;
	return (EXIT_SUCCESS);
}
