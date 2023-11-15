#include "shell.h"
/**
 * FreeArray - free the array from strings.
 *
 * @array: 2d array of strings;
 *
 * Return: Nothing
*/

void FreeArray(char **array)
{
	int i = 0;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

/**
 * _itoa - integer to ascii
 *
 * @n: the integer
 *
 * Return: ascii
*/

char *_itoa(int n)
{
	char buff[20];
	int i = 0;

	if (n == 0)
	{
		buff[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buff[i] = "\0";
	rev_str(buff, i);

	return (my_strdup(buff));
}

/**
 * rev_str - reverse a string.
 *
 * @str: the string
 * @length: length
 *
 * Return: nothing
 */
void rev_str(char *str, int length)
{
	char temp;
	int s = 0, e = length - 1;

	while (s < e)
	{
		temp = str[s];
		str[s] = str[e];
		str[e] = temp;
		s++;
		e--;
	}
}

/**
 * display_error - prints error.
 *
 * @name: the name
 * @cmd: the command
 * @index: index
 *
 * Return: nothing.
 */

void display_error(char *name, char *cmd, int index)
{
	char *idx, errorr[] = ": not found\n";

	idx = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", _strlen(name));
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, errorr, _strlen(errorr));
	free(idx);
}
