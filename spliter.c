#include "shell.h"

/**
 * spliter - function that slplit a line a separated strings.
 *
 * @line: a pointer to the line to split.
 *
 * Return: a pointer to the array of strings.
 */

char **spliter(char *line)
{
	char **tokens = NULL, *token = NULL;
	char *tmp = NULL;
	int count = 0, i = 0;

	if (!line)
	{
		return (NULL);
	}
	tmp = my_strdup(line);
	token = strtok(tmp, SEP);
	while (token)
	{
		count++;
		token = strtok(NULL, SEP);
	}
	free(tmp);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
	{
		free(line);
		return (NULL);
	}
	token = strtok(line, SEP);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, SEP);
		i++;
	}
	free(line);
	line = NULL;
	return (tokens);
}
