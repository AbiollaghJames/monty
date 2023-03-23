#include "monty.h"

int malloc_error(void);
int usage_error(void);
int f_open_error(char *filename);

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
	fprintf(stderr, "Error: Can't open file", filename);
	return (EXIT_FAILURE);
}
