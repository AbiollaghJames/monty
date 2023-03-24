#include "monty.h"

int malloc_error(void);
int usage_error(void);
int f_open_error(char *filename);
int invalid_instruction(char *opcode, unsigned int line_number);
int not_int_error(unsigned int line_number);

/**
 * malloc_error - prints mem alloation error
 * Return: EXIT FAILURE
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * usage_error - prints usage error
 * Return: EXIT FAILURE
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints file opening error
 * @filename: File to be opened
 * Return: EXIT FAILURE
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s", filename);
	return (EXIT_FAILURE);
}

/**
 * invalid_instruction - prints ints error
 * @line_number: number where instr error occurs
 * Return: EXIT FAILURE
 */
int invalid_instruction(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * not_int_error - prints error is line_number isn't int
 * @line_number: args to be checked
 * Return: EXIT FAILURE
 */
int not_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer", line_number);
	return (EXIT_FAILURE);
}
