#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/**
 * push - pushes elem to stack_t list
 * @stack: pointer to topnode of list/head
 * @line_number: current line number of monty bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		op_tok_errors(malloc_error());
		return;
	}

	if (op_tok[1] == NULL)
	{
		op_tok_errors(not_int_error(line_number));
		return;
	}

	for (i = 0; op_tok[1][i]; i++)
	{
		if (op_tok[1][i] == '-' && i == 0)
			continue;
		if (op_tok[1][i] < '0' || op_tok[1][i] > '9')
		{
			op_tok_errors(not_int_error(line_number));
			return;
		}
	}
	new_node->n =  atoi(op_tok[1]);

	if (mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = temp;

		if (temp)
			temp->next = new_node;
		(*stack)->next = new_node;
	}
	else
	{
		temp = *stack;

		while (temp->next)
			temp = temp->next;
		new_node->prev = temp;
		new_node->next = NULL;
		temp->next = new_node;
	}
}

/**
 * pall - prints stack_t list
 * @stack: pointer to top of stack
 * @line_number: working line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}
/**
 * pint - prints top most val of stack_t
 * @stack: pointer to top of stack_t
 * @line_number: working line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		op_tok_errors(pint_err(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}
/**
* pop - removes top elem of stack_t list
* @stack: pointer to top of stack
* @line_number: current working no
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nxt = NULL;

	if ((*stack)->next == NULL)
	{
		op_tok_errors(pop_err(line_number));
		return;
	}
	nxt = (*stack)->next->next;
	free((*stack)->next);

	if (nxt)
		nxt->prev = *stack;
	(*stack)->next = nxt;
}
/**
 * swap - swaps top two elems
 * @stack: pointer to top elem
 * @line_number: working line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_errors(short_s_err(line_number, ""));
		return;

	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;

	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
