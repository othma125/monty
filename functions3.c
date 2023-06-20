#include "monty.h"
/**
 * rotl - rotl
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
}
/**
 * rotr - rotr
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
}
/**
 * stack - stack
 * @stack: stack
 * @line_number: integer
 * Return: none
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
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
