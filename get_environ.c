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
	char *envo;

	for (i = 0; environ[i]; i++)
	{
		temp = my_strdup(environ[i]);
		cke = strtok(temp, "=");
		if (my_strcmp(cke, var) == 0)
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
