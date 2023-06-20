#include "monty.h"
/**
 * main - interpreter function
 * @argc: the count of arguments count
 * @argv: arguments set
 * Return: success or failure
 */

char **op_toks = NULL;

int main(int argc, char **argv)
{
	FILE *monty_file = NULL;
	int exit_stat;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	exit_stat = monty(monty_file);
	fclose(monty_file);
	return (exit_stat);
}
