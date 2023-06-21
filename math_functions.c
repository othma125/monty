#include "monty.h"
/**
 * add - add
 * @stack: stack
 * @number: integer
 * Return: success
 */
void add(stack_t **stack, unsigned int number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, number);
	return (EXIT_SUCCESS);
}

/**
 * sub - sub
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
	return (EXIT_SUCCESS);
}

/**
 * _div - div
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
	return (EXIT_SUCCESS);
}

/**
 * mul - mul
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
	return (EXIT_SUCCESS);
}
/**
 * mod - modulo
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
	return (EXIT_SUCCESS);
}
