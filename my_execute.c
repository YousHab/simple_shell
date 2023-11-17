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

int my_execute(char **command_line, char **av, int index)
{
	int status;
	pid_t child_process;
	char *cmd;

	cmd = get_path(command_line[0]);
	if (!cmd)
	{
		display_error(av[0], command_line[0], index);
		FreeArray(command_line);
		return (127);
	}

	child_process = fork();
	if (child_process == 0)
	{
		if (execve(command_line[0], command_line, environ) == -1)
		{
			free(cmd);
			cmd = NULL;
			FreeArray(command_line);
		}
	}
	else
	{
		waitpid(child_process, &status, 0);
		FreeArray(command_line);
		free(cmd);
		cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
