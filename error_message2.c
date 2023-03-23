#include "monty.h"

int pint_err(unsigned int line_number);
int pop_err(unsigned int line_number);
int short_s_err(unsigned int line_number, char *c);
int unknown_op_error(char *opcode, unsigned int line_number);
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
/**
 * short_s_err - prints short err
 * @line_number: working line
 * @c: char
 */
int short_s_err(unsigned int line_number, char *c)
{
	fprintf(stderr, "L%u: can't %s, stack too short \n", line_number, c);
	return (EXIT_FAILURE);
}
/**
 * div_error - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
