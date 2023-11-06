#include "shell.h"

int main(int ac, char **av)
{
	(void)ac;
	char *buffer = NULL;
	size_t buffer_size = 0;
	size_t n_char = 0;
	
	write(1,"$ ", 2);

	n_char = getline(&buffer, &buffer_size, stdin);
	if (n_char == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", buffer);

	return (0);
}
