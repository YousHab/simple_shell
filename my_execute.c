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

int my_execute(char **command_line, char **av, int index, char **envp)
{
	int status;
	char *cmd;
	pid_t child;

	cmd = get_path(command_line[0]);
	if (!cmd)
	{
		display_error(av[0], command_line[0], index);
		FreeArray(command_line);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(command_line[0], command_line, envp) == -1)
		{
			free(cmd);
			cmd = NULL;
			FreeArray(command_line);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		FreeArray(command_line);
		free(cmd);
		cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
