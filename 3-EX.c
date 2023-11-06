#include "shell.h"

char **split(char **str)
{
	char *token = NULL; /* each string */
	char **tokens = NULL; /* The array that contains tokens */ 
	int i = 0;

	token = strtok(*str, " \t\n");
	while (token)
	{
		i++;
		tokens = realloc(tokens, i * sizeof(char *));
		if (tokens == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char *buffer = NULL;
	size_t n = 0;
	int n_char = 0;
	char **tokens = NULL;
	int i = 0;

	write(1, "$ ", 2);
	n_char = getline(&buffer, &n, stdin);
	if (n_char == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	buffer[n_char - 1] = '\0';
	tokens = split(&buffer);
	while(tokens)
	{
		printf("%s\n", tokens[i]);
		i++;
	}
	return (0);
}
