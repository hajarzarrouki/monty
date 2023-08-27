#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!g_var.arg)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "usage: push integer\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}

	for (j = 0; g_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(g_var.arg[j]) && g_var.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", cline);
			fprintf(stderr, "usage: push integer\n");
			free_global_var();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(g_var.arg);

	if (g_var.lifo == 1)
		add_node_head(doubly, n);
	else
		add_node_end(doubly, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
