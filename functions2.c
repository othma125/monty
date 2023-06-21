#include "monty.h"
/**
 * nop - nop
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * pchar - pchar
 * @stack: stack
 * @number: integer
 * Return: none
 */
void pchar(stack_t **stack, unsigned int number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", number);
		success = 0;
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", number);
		success = 0;
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
/**
 * pstr - pstr
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	(void)line_number;
	while (tmp && tmp->n > 0 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * stack - stack
 * @stack: stack
 * @number: integer
 * Return: none
 */
void stack(stack_t **stack, unsigned int number)
{
	(void)number;
	(*stack)->n = STACK;
}
/**
 * queue - change stack to queue
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(*stack)->n = QUEUE;
}
