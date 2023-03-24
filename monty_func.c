#include "monty.h"
/**
 * push - push elems to top of stack
 * @stack: linked list implementation of stack
 * @line_number: working line
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	char **argv;
	int d;

	argv = lexer(line);
	if ((argv[1] == NULL || _isdigit(argv[1]) != 1))
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		free(argv[0]);
		free(argv);
		exit(EXIT_FAILURE);
	}
	d = atoi(argv[1]);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(new);
		exit(EXIT_FAILURE);
	}
	new->n = d;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	free(argv);
}
/**
 * pall - prints a stack
 * @stack: list
 * @line_number: working line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	print_l(*stack);
}

/**
 * pint - prints top of stack
 * @stack: linked list
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		free(line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - pop elem from top of stack
 * @stack: pointer to top
 * @line_number: working line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		free(line);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
