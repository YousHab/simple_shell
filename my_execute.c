#include "shell.h"

/**
 * my_execute - function that execute a command line.
 *
 * @command_line: the command
 * @av: arguments.
 * @index: the index.
 *
 * Return: the status.
 */

int my_execute(char **command_line, char **av)
{
	int status;
	pid_t child_process;

	child_process = fork();
	if (child_process == 0)
	{
		if (execve(command_line[0], command_line, environ) == -1)
		{
			perror(av[0]);
			FreeArray(command_line);
			exit(0);
		}
	}
	else
	{
		waitpid(child_process, &status, 0);
		FreeArray(command_line);
	}
	return (WEXITSTATUS(status));
}
