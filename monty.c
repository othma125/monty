#include "monty.h"

/**
 * readLine - check code
 * @file: input stream
 * @line: string to read
 * Return: string length
 */
unsigned int readLine(FILE *file, char **line)
{
	unsigned int max_len = 128, len = 0;
	char ch = getc(file);

	*line = malloc(max_len);
	if (*line == NULL)
		return (0);
	while ((ch != '\n') && (ch != EOF))
	{
		(*line)[len] = ch;
		len++;
		ch = getc(file);
	}
	(*line)[len] = '\0';
	return (len);
}
/**
 * function_selector - select the right function in term of opcode
 * @opcode: The opcode to match.
 * Return: function pointer
 */
void (*function_selector(char *opcode))(stack_t**, unsigned int)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; functions[i].opcode; i++)
		if (strcmp(opcode, functions[i].opcode) == 0)
			return (functions[i].f);
	return (NULL);
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
	int exit_stat = EXIT_SUCCESS, free;
	void (*op_func)(stack_t**, unsigned int);

	if (create_stack(&stack) == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	while (success && readLine(f, &line) >= 0)
	{
		number++;
		free = 0;
		printf("%s\n", line);
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		op_toks = _strtok(line);
		if (args_count(op_toks) == 0)
		{
			free(line);
			_free(op_toks);
			continue;
		}
		op_func = function_selector(op_toks[0]);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, op_toks[0]);
			break;
		}
		free(line);
		_free(op_toks);
		free = 1;
	}
	if (free == 0)
	{
		free(line);
		_free(op_toks);
	}
	free_stack(&stack);
	return (exit_stat);
}
