#include "monty.h"
/**
 * add - add
 * @op_toks: tokens 
 * @stack: stack
 * @number: integer
 * Return: success
 */
int add(char ** op_toks, stack_t **stack, unsigned int number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n += (*stack)->next->n;
	return (pop(op_toks, stack, number));
}

/**
 * sub - sub
 * @op_toks: tokens 
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int sub(char ** op_toks, stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	return (pop(op_toks, stack, line_number));
}

/**
 * _div - div
 * @op_toks: tokens 
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int _div(char ** op_toks, stack_t **stack, unsigned int line_number)
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
	return (pop(op_toks, stack, line_number));
}

/**
 * mul - mul
 * @op_toks: tokens 
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int mul(char ** op_toks, stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	return (pop(op_toks, stack, line_number));
}
/**
 * mod - modulo
 * @op_toks: tokens 
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int mod(char ** op_toks, stack_t **stack, unsigned int line_number)
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
	return (pop(op_toks, stack, line_number));
}
