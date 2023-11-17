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
	char *temp = NULL;
	int count = 0, i = 0;

	if (!line)
	{
		return (NULL);
	}
	temp = my_strdup(line);
	token = strtok(temp, SEP);
	if (!token)
	{
		free(temp);
		temp = NULL;
		free(line);
		line = NULL;
	}
	while (token)
	{
		count++;
		token = strtok(NULL, SEP);
	}
	free(temp), temp = NULL;

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
	{
		free(line);
		return (NULL);
	}
	token = strtok(line, SEP);
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, SEP);
	}
	free(line);
	line = NULL;
	tokens[i] = NULL;
	return (tokens);
}
