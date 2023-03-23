#include "monty.h"

void free_s(stack_t **stack);
int initialize_s(stack_t **stack);
int mode(stack_t *stack);

/**
 * free_s - frees stack_t stack
 * @stack: pointer to 1st/top of stack or bottom of queues of stack_t
 */
void free_s(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * initialize_s - initializes stack_t with beg stack and ending queue
 * @stack: pointer to uninitialized stack_t
 * Return: EXIT FAILURE on error and EXIT SUCCESS on success
 */
int initialize_s(stack_t **stack)
{
	stack_t *s = malloc(sizeof(stack_t));

	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * mode - checks if stack_t list is in stack or queue mode
 * @stack: pointer to top of stack || bottom of queue
 * Return: STACK (0) if stack || QUEUE(1) if queue elese 2
 */
int mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
