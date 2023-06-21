#include "monty.h"
/**
 * push - monty push
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int push(char **op_toks, stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	if (args_count(op_toks) != 2)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_toks[0]);
		return (EXIT_FAILURE);
	}
	new->n = atoi(op_toks[1]);
	if ((*stack)->n == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
	return (EXIT_SUCCESS);
}
/**
 * pall - monty pall
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pall(char **op_toks, stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	(void)line_number;
	(void)op_toks;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
/**
 * pint - monty pint
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pint(char **op_toks, stack_t **stack, unsigned int line_number)
{
	(void)op_toks;
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
	return (EXIT_SUCCESS);
}
/**
 * pop - monty pop
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pop(char **op_toks, stack_t **stack, unsigned int line_number)
{
	stack_t *nxt = NULL;

	(void)op_toks;
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return (EXIT_FAILURE);
	}
	nxt = (*stack)->next->next;
	free((*stack)->next);
	if (nxt)
		nxt->prev = *stack;
	(*stack)->next = nxt;
	return (EXIT_SUCCESS);
}

/**
 * swap - monty swap
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int swap(char **op_toks, stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)op_toks;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	return (EXIT_SUCCESS);
}
