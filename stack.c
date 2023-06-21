#include "monty.h"
/**
 * free_stack - check code
 * @stack: stack
 * return: none
 */
void free_stack(stack_t **stack)
{
	stack_t *node = *stack;

	while (*stack)
	{
		node = (*stack)->next;
		free(*stack);
		*stack = node;
	}
}

/**
 * create_stack - check code
 * @stack: stack
 * Return: none
 */
void create_stack(stack_t **stack)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		success = 0;
		return;
	}
	node->n = STACK;
	node->prev = NULL;
	node->next = NULL;
	*stack = node;
}
