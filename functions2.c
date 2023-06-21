#include "monty.h"
/**
 * nop - nop
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return (EXIT_SUCCESS);
}
/**
 * pchar - pchar
 * @stack: stack
 * @number: integer
 * Return: success
 */
int pchar(stack_t **stack, unsigned int number)
{
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
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	(void)line_number;
	while (tmp && tmp->n > 0 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
/**
 * stack - stack
 * @stack: stack
 * @number: integer
 * Return: success
 */
int stack(stack_t **stack, unsigned int number)
{
	(void)number;
	(*stack)->n = STACK;
	return (EXIT_SUCCESS);
}
/**
 * queue - change stack to queue
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(*stack)->n = QUEUE;
	return (EXIT_SUCCESS);
}
