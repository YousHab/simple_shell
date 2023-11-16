#include "shell.h"

/**
 * get_path - a function that return the path.
 *
 * @line: the command line
 *
 * Return: the path.
 */

char *get_path(char *line)
{
	char *pathEnv, *cmd, *dir;
	struct stat st;
	int j;

	for (j = 0; line[j]; j++)
	{
		if (line[j] == '/')
		{
			if (stat(line, &st) == 0)
				return (my_strdup(line));
			return (NULL);
		}
	}
	pathEnv = get_environ("PATH");
	if (pathEnv == NULL)
		return (NULL);
	dir = strtok(pathEnv, ":");
	while (dir)
	{
		cmd = malloc(_strlen(dir) + _strlen(line) + 2);
		if (cmd)
		{
			_strcpy(cmd, dir);
			_strcat(cmd, "/");
			_strcat(cmd, line);
			if (stat(cmd, &st) == 0)
			{
				free(pathEnv);
				return (cmd);
			}
			free(cmd);
			cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(pathEnv);
	return (NULL);
}
