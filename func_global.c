#include "monty.h"

/**
 * free_global_var - frees the global variables
 * Return: no return
 */
void free_global_var(void)
{
	free_list(g_var.head);
	free(g_var.buffer);
	fclose(g_var.fd);
}

/**
 * start_g_var - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_g_var(FILE *fd)
{
	g_var.lifo = 1;
	g_var.arg = NULL;
	g_var.head = NULL;
	g_var.fd = fd;
	g_var.buffer = NULL;
}
