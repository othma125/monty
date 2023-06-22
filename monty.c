#include "monty.h"

/**
 * free_tokens - frees
 * @op_toks: tokens
 * @line: string
 * @free_condition: condition
 * Return: none
 */
void free_tokens(char **op_toks, char *line, int free_condition)
{
	if (free_condition == 0)
	{
		if (line)
			free(line);
		if (op_toks)
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
unsigned int args_count(char **args)
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
	unsigned int number = 0, exit_stat = EXIT_SUCCESS, free_cndtn = 0;
	char *line = NULL, **op_toks = NULL;
	stack_t *stack = NULL;
	int (*func)(char **, stack_t**, unsigned int);

	if (create_stack(&stack) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	while (readLine(f, &line) > 0)
	{
		number++, free_cndtn = 0;
		if (line[0] == '#' || line[0] == '\n')
		{
			free(line);
			continue;
		}
		op_toks = _strtok(line);
		if (args_count(op_toks) == 0 || op_toks[0][0] == '#'
			|| (op_toks[1] && op_toks[1][0] == '#'))
		{
			free_tokens(op_toks, line, free_cndtn);
			continue;
		}
		func = function_selector(op_toks[0]);
		if (func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				number, op_toks[0]);
			exit_stat = EXIT_FAILURE;
			break;
		}
		if (func(op_toks, &stack, number) == EXIT_FAILURE)
		{
			exit_stat = EXIT_FAILURE;
			break;
		}
		free(line), _free(op_toks), free_cndtn = 1;
	}
	free_tokens(op_toks, line, free_cndtn), free_stack(&stack);
	return (exit_stat);
}
