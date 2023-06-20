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
 * Return: success
 */
int create_stack(stack_t **stack)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (0);
	node->n = STACK;
	node->prev = NULL;
	node->next = NULL;
	*stack = node;
	return (1);
}
