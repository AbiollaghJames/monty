#include "monty.h"

int pint_err(unsigned int line_number);
int pop_err(unsigned int line_number);
/**
 * pint_err - prints pint error message
 * @line_number: line_num where error occured
 * Return: EXIT FAILURE
 */
int pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: Can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * pop_err - prints pop err message
 * @line_number: line num where err occured
 * Return: EXIT FAILURE
 */
int pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
