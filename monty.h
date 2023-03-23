#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_tok;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* STACK OPERATIONS */
void free_s(stack_t **stack);
int initialize_s(stack_t **stack);
int mode(stack_t *stack);
void free_toks(void);
unsigned int len_tok(void);
int monty(FILE *script_fd);

/* OPCODE FUNCTIONS */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divs(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

char **strtow(char *str, char *delims);
char *get_int (int n);

/* ERROR MESSAGES */
int malloc_error(void);
int usage_error(void);
int f_open_error(char *filename);
int invalid_intstruction(char *opcode, unsigned int line_number);
int not_int_error(unsigned int line_number);
void op_tok_errors(int err_code);
int pint_err(unsigned int line_number);
int pop_err(unsigned int line_number);
int short_s_err(unsigned int line_number, char *c);
int unknown_op_error(char *opcode, unsigned int line_number);
int pint_err(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
#endif
