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
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			op_funcs[i].f(stk, n);
}
