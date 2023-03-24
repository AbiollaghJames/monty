#include "monty.h"
/**
 * main - entry point
 * @argc: args count
 * @argv: args vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	FILE *fd = fopen(argv[1], "r");
	int len;
	char **av, *line_cpy = malloc(100);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(100);
	while (fgets(line, 500, fd))
	{
		strcpy(line_cpy, line);
		av = lexer(line_cpy);
		len = list_len(head);
		(*get_func(av[0]))(&head, len);
		free(av);
	}
	free(line_cpy);
	free(line);
	free_list(head);
	fclose(fd);
	return (EXIT_SUCCESS);
}
