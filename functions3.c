#include "monty.h"
/**
 * rotl - rotl
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int rotl(char **op_toks, stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;
	(void)op_toks;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return (EXIT_SUCCESS);
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
	return (EXIT_SUCCESS);
}
/**
 * rotr - rotr
 * @op_toks: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int rotr(char **op_toks, stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;
	(void)op_toks;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return (EXIT_SUCCESS);
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
	return (EXIT_SUCCESS);
}
