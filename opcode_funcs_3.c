#include "monty.h"
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/**
 * nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		op_tok_errors(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		op_tok_errors(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");

	(void)line_number;
}
