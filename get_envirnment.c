#include "shell.h"
/**
 * get_environ - return the environment
 *
 * @var: environment variable.
 *
 * Return: the environment.
 */

char *get_environ(char *var)
{
	int j = 0;
	char *temp;
	char *k, *val, *envi;

	for (j = 0; environ[j]; j++)
	{
		temp = my_strdup(environ[j]);
		k = strtok(temp, "=");
		if (my_strcmp(k, var) == 0)
		{
			val = strtok(NULL, "\n");
			envi = my_strdup(val);
			free(temp);
			return (envi);
		}
		free(temp);
		temp = NULL;
	}
	return (NULL);
}

/**
 * get_path - to get the path.
 *
 * @line: the line from the stdin.
 *
 * Return: path
 */

char *get_path(char *line)
{
	struct stat stt;
	char *pathEnv, *cmd, *directory;
	int j = 0;

	for (j = 0; line[j]; j++)
	{
		if (line[j] == '/')
		{
			if (stat(line, &stt) == 0)
				return (my_strdup(line));
			return (NULL);
		}
	}
	pathEnv = get_environ("PATH");
	if (pathEnv == NULL)
	{
		return (NULL);
	}
	directory = strtok(pathEnv, ":");
	while (directory != NULL)
	{
		cmd = malloc(_strlen(directory) + _strlen(line) + 2);
		if (cmd)
		{
			_strcpy(cmd, directory);
			_strcat(cmd, "/");
			_strcat(cmd, line);
			if (stat(cmd, &stt) == 0)
			{
				free(pathEnv);
				return (cmd);
			}
			free(cmd);
			cmd = NULL;
			directory = strtok(NULL, ":");
		}
	}
	free(pathEnv);
	return (NULL);
}
