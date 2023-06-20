#include "monty.h"
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
 * monty - check code
 * @f: monty file
 * Return: success
 */
int monty(FILE *f)
{
	unsigned int number = 0;
	char *line = NULL, **tokens;
	stack_t *stack = NULL;
	int exit_stat = EXIT_SUCCESS;
	size_t len;

	if (create_stack(&stack) == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	while (getline(&line, &len, f))
	{
		number++;
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
	}
	free(line);
	free_stack(&stack);
	return (exit_stat);
}
