#include "monty.h"
/**
 * push - monty push
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}
	if (op_toks[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return;
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
}
/**
 * pall - monty pall
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	(void)line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - monty pint
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return;
	}
	printf("%d\n", (*stack)->next->n);
}
/**
 * pop - monty pop
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nxt = NULL;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return;
	}
	nxt = (*stack)->next->next;
	free((*stack)->next);
	if (nxt)
		nxt->prev = *stack;
	(*stack)->next = nxt;
}

/**
 * swap - monty swap
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
