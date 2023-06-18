/**
 * function_selector - select the right function in term of opcode
 * @opcode: The opcode to match.
 * @stk: stack list
 * @n: unsigned number
 * Return: none
 */
void function_selector(char *opcode, stack_t** stk, unsigned int n)
{
	instruction_t op_funcs[] = {
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

	for (i = 0; op_funcs[i].opcode; i++)
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			op_funcs[i].f(stk, n);
}
