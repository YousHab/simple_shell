#include "shell.h"

/**
 * readline - a function that read a line from the stdin.
 *
 * Return: a pointer to the read line.
 */

char *readline(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	int n_char = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n_char = getline(&buffer, &buffer_size, stdin);
	if (n_char == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

