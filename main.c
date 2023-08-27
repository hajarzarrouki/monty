#include "monty.h"

global_var_t g_var;

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 * @ac: vars count
 * @av: vars array
 * Return: file struct
 */
FILE *check_input(int ac, char *av[])
{
	FILE *fd;

	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - entry to the program
 * @ac: vars count
 * @av: vars array
 * Return: Something
 */
int main(int ac, char *av[])
{
	void (*func)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 0;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};
	unsigned int cont = 1;

	fd = check_input(ac, av);
	start_g_var(fd);
	nlines = getline(&g_var.buffer, &size, fd);

	while (nlines != -1)
	{
		lines[0] = _strtokey(g_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			func = get_opcodes(lines[0]);
			if (!func)
			{
				fprintf(stderr, "L%u: ", cont);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_global_var();
				exit(EXIT_FAILURE);
			}
			g_var.arg = _strtokey(NULL, " \t\n");
			func(&g_var.head, cont);
		}
		nlines = getline(&g_var.buffer, &size, fd);
		cont++;
	}
	free_global_var();
	return (0);
}
