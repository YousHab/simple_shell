#include "shell.h"

/**
 * main - a a UNIX command line interpreter.
 *
 * @ac: nb of parameters.
 * @av: arguments.
 *
 * Return: 0.
 */


int main(int ac, char **av)
{
	char *line = NULL;
	char **command_line = NULL;
	int status = 0;
	(void)ac;

	while (1)
	{
		line = readline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command_line = spliter(line);
		if (!command_line)
		{
			continue;
		}
		status = my_execute(command_line, av);
	}
}
