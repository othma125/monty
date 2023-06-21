#include "monty.h"

/**
 * free_tokens - frees
 * @line: strng
 * @free_condition: condition
 * Return: none
 */
void free_tokens(char *line, int free_condition)
{
	if (free_condition == 0)
	{
		free(line);
		_free(op_toks);
	}
}
/**
 * _free - frees
 * @tokens: operation tokens
 * Return: none
 */
void _free(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;
	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}
/**
 * args_count - check code
 * @args: arguments
 * Return: argc
 */
int args_count(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}
/**
 * monty - check code
 * @f: monty file
 * Return: success
 */
int monty(FILE *f)
{
	unsigned int number = 0;
	char *line = NULL;
	stack_t *stack = NULL;
	int exit_stat = EXIT_SUCCESS, free_condition;
	void (*func)(stack_t**, unsigned int);

	if (create_stack(&stack) == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	while (success && readLine(f, &line) > 0)
	{
		number++;
		free_condition = 0;
		printf("%s\n", line);
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		op_toks = _strtok(line);
		if (args_count(op_toks) == 0)
		{
			free_tokens(line, free_condition);
			continue;
		}
		func = function_selector(op_toks[0]);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				number, op_toks[0]);
			break;
		}
		func(&stack, number);
		free(line);
		_free(op_toks);
		free_condition = 1;
	}
	free_tokens(line, free_condition);
	free_stack(&stack);
	return (exit_stat);
}
