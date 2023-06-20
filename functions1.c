#include "monty.h"
/**
 * push - monty push
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new = malloc(sizeof(stack_t));
	int i;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (0);
	}
	if (op_toks[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return (0);
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
	return (1);
}
/**
 * pall - monty pall
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	(void)line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return (1);
}
/**
 * pint - monty pint
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (0);
	}
	printf("%d\n", (*stack)->next->n);
	return (1);
}
/**
 * pop - monty pop
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nxt = NULL;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return (0);
	}
	nxt = (*stack)->next->next;
	free((*stack)->next);
	if (nxt)
		nxt->prev = *stack;
	(*stack)->next = nxt;
	return (1);
}

/**
 * swap - monty swap
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return (0);
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	return (1);
}
