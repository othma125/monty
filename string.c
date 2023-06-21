#include "monty.h"
/**
 * _atoi - atoi
 * @s: string
 * Return: success
 */
int _atoi(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-' && i == 0)
			continue;
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * readLine - check code
 * @file: input stream
 * @line: string to read
 * Return: string length
 */
unsigned int readLine(FILE *file, char **line)
{
	unsigned int max_len = 128, len = 0;
	char ch;

	*line = malloc(max_len);
	if (*line == NULL)
		return (0);
	do {
		ch = getc(file);
		(*line)[len] = ch;
		len++;
	} while (ch != '\n' && ch != EOF);
	(*line)[len] = '\0';
	return (len);
}
/**
 * _calloc - allocates memory for an array, using malloc.
 *
 * @nmemb: number of members
 * @size: size
 *
 * Return: pointer or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < size * nmemb; i++)
		p[i] = 0;
	return (p);
}
/**
 * exists_within - check code
 * @c: character
 * @s: string
 * Return: boolean
 */
int exists_within(char c, char *s)
{
	if (*s == '\0')
		return (c == *s);
	return (c == *s ? 1 : exists_within(c, s + 1));
}
/**
 * _strtok - check code
 * @s: string
 * Return: tokens set
 */
char **_strtok(char *s)
{
	char **tokens;
	size_t j = 0, i, len = strlen(s) + 1;
	int found = 1, k = 0;

	tokens = (char **)_calloc(len * sizeof(char *), sizeof(char));
	*tokens = (char *)_calloc(len, sizeof(char));
	if (!*tokens)
		free(tokens);
	for (i = 0; s[i]; i++)
	{
		if (exists_within(s[i], DELIMS))
		{
			if (!found)
			{
				tokens[k++][j] = '\0';
				tokens[k] = (char *)_calloc(len, sizeof(char));
				if (!tokens[k])
					_free(tokens);
			}
			found = 1;
			j = 0;
		}
		else
		{
			tokens[k][j++] = s[i];
			found = 0;
		}
	}
	if (found)
	{
		free(tokens[k]);
		tokens[k] = NULL;
	}
	else
		tokens[k][j] = '\0';
	return (tokens);
}
