
#include "monty.h"
/**
 * main - interpreter function
 * @argc: the count of arguments count
 * @argv: arguments set
 * Return: success or failure
 */

int main(int argc, char **argv)
{
  FILE *script_file = NULL;
  int exit_stat = 0;

  if (argc != 2)
  {
    fprintf(stderr, "USAGE: monty file\n");
    return (1);
  }
  script_file = fopen(argv[1], "r");
  if (!script_file)
  {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    return (1);
  }
  exit_stat = monty(script_file);
	fclose(script_file);
	return (exit_stat);
}
