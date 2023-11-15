#include "shell.h"

/**
 * my_execute - function that execute a command line.
 * 
 * @command_line: the command
 * @av: arguments.
 * 
 * Return: the status.
*/

int my_execute(char **command_line, char **av, int index)
{
    pid_t child;
    int stat;
    char **env;
    char *cmd;

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
        if (execve(command_line[0], command_line, env) == -1)
        {
            free(cmd);
            cmd = NULL;
            FreeArray(command_line);
        }
    }
    else
    {
        waitpid(child, &stat, 0);
        FreeArray(command_line);
        free(cmd);
        cmd = NULL;
    }
    return (WEXITSTATUS(stat));
}