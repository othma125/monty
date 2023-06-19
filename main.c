#include "monty.h"
/**
 * main - interpreter function
 * @argc: the count of arguments count
 * @argv: arguments set
 * Return: success or failure
 */
int main(int argc, char **argv)
{
	FILE *monty_file = NULL;
	int exit_stat = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (1);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (1);
	}
	exit_stat = monty(monty_file);
	fclose(monty_file);
	return (1 - exit_stat);
}
