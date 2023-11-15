#include "shell.h"

/**
 * get_environ - function to get environ.
 *
 * @var: path.
 *
 * Return: environment
 *
 */

char *get_environ(char *var)
{
	int i = 0;
	char *temp, *cke, *value;

	for (i = 0; env[i]; i++)
	{
		temp = my_strdup(env[i]);
		cke = strtok(temp, "=");
		if (my_strcmp(cke, var))
		{
			value = strtok(NULL, "\n");
			envo = my_strdup(value);
			free(temp);
			return (envo);
		}
		free(temp);
		temp = NULL;
	}
	return (NULL);
}
