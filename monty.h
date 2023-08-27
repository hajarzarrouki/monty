#ifndef MONTY_H
#define MONTY_H

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>


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

/**
 * struct global_var - global structure for global variable
 * @lifo: is stack or queue
 * @arg: args
 * @head: linked list head
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_var
{
	int lifo;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_var_t;

extern global_var_t g_var;

/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);



/* doubly linked list functions */
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node_head(stack_t **head, const int n);
void free_list(stack_t *head);

/* File Check */
FILE *check_input(int argc, char *argv[]);


/* opcode_instructuions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);
void _add(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);
void _mul(stack_t **head, unsigned int counter);
void _mod(stack_t **head, unsigned int counter);


/* String functions*/
int _strcmp(char *s1, char *s2);
char *_strtokey(char *s, char *d);
int _sch(char *s, char c);

/* global variable */
void start_g_var(FILE *fd);
void free_global_var(void);

#endif
