#include "monty.h"
/**
 * function_selector - select the right function in term of opcode
 * @opcode: The opcode to match.
 * @stk: stack list
 * @n: unsigned number
 * Return: success or failure
int function_selector(char *opcode, stack_t **stk, unsigned int n)
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
		{"div", div},
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
		{
			functions[i].f(stk, n);
			return (1);
		}
	return (0);
}
 */
/**
 * _free - frees
 * @tokens: operation tokens
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
 * return: success
 */
int monty(FILE *f)
{
	unsigned int number = 0;
	char *line = NULL, **tokens;
	stack_t *stack = NULL;
	int exit_stat = 1;

	if (create_stack(&stack) == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (1);
	}
	while (fgets(line, sizeof(line), f))
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
