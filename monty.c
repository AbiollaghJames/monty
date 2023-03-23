#include "monty.h"
#include <string.h>

void free_toks(void);
unsigned int len_tok(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int monty(FILE *script_fd);

/**
 * free_toks - Frees the global op_toks array of strings.
 */
void free_toks(void)
{
	size_t i = 0;

	if (op_tok == NULL)
		return;

	for (i = 0; op_tok[i]; i++)
		free(op_tok[i]);

	free(op_tok);
}

/**
 * len_tok - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int len_tok(void)
{
	unsigned int toks_len = 0;

	while (op_tok[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divs},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (initialize_s(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_tok = strtow(line, DELIMS);
		if (op_tok == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_s(&stack);
			return (malloc_error());
		}
		else if (op_tok[0][0] == '#') /* comment line */
		{
			free_toks();
			continue;
		}
		op_func = get_op_func(op_tok[0]);
		if (op_func == NULL)
		{
			free_s(&stack);
			exit_status = unknown_op_error(op_tok[0], line_number);
			free_toks();
			break;
		}
		prev_tok_len = len_tok();
		op_func(&stack, line_number);
		if (len_tok() != prev_tok_len)
		{
			if (op_tok && op_tok[prev_tok_len])
				exit_status = atoi(op_tok[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_toks();
			break;
		}
		free_toks();
	}
	free_s(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
