#include "monty.h"
/**
 * _isascii - checks if the given character decimal value is between 0 and 127
 * @c: integer value
 *
 * Return: non-zero values if ASCII. Otherwise, 0
 */
int _isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/**
 * pchar - prints the int at the top of the stack as char
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	if (_isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
