#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - Nope doesn't do anythinhg
 *
 * @doubly: head of the linked list
 * @cline: line number
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
