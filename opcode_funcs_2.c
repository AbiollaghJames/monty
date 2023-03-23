#include "monty.h"
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/**
 * add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the sec val node.
 */
void add(stack_t **stack, unsigned int line_number) 
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_errors(short_s_err(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * sub - subs sec val from top
 * @stack: pointer to top
 * @line_number: current working line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_errors(short_s_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * div - divs sec val to top
 * @stack: pointer to top
 * @line_number: working line no
 */
void div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_errors(short_s_err(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_errors(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * mul - muls sec val to top
 * @stack: pointer to top
 * @line_number: working line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_errors(short_s_errors(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * mod - mods sec val to top
 * @stack: pointer to top
 * @line_number: working line
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_errors(short_s_errors(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		op_tok_errors(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
