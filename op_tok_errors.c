#include "monty.h"
/**
 * op_tok_errors - puts last elem of op_tok to err code
 * @err_code: int to store as str in op_tok
 */
void op_tok_errors(int err_code)
{
	int tok_len = 0, i = 0;
	char *ext_str = NULL;
	char **new_tok = NULL;

	tok_len = len_tok();
	new_tok = malloc(sizeof(char *) * (tok_len + 2));

	if (!op_tok)
	{
		malloc_error();
		return;
	}

	while (i < tok_len)
	{
		new_tok[i] = op_tok[i];
		i++;
	}
	ext_str = get_int(err_code);

	if (!ext_str)
	{
		free(new_tok);
		malloc_error();
		return;
	}
	new_tok[i++] = ext_str;
	new_tok[i] = NULL;
	free(op_tok);
	op_tok = new_tok;
}
