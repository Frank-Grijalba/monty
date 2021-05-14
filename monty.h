#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/******************* STRUCTS *********************/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct sets - settings
 * @file: file
 * @line: line
 * @stack: stack
 */
typedef struct sets
{
	char *line;
	FILE *file;
	stack_t *stack;
} sets_t;

/*variable global*/
extern sets_t settings;
sets_t settings;
/******************* END /STRUCTS *********************/

/******************** monty_exec **********************/
stack_t *_push(stack_t **head, int n);
void open_file(char *arg);
void exec_foo(stack_t **stack, char *opcode, int ln);

/******************* monty_tools **********************/
void clean(void);
void reset(void);
int is_int(char *s);
void free_stack(stack_t *head);

/*************** monty_foo **************/
void _pall(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/*************** monty_math **************/
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
/****************** ERRORS *******************/
#define ERROR_USAGE 1
#define ERROR_OPEN_FILE 2
#define ERROR_OF_MALLOC 3
#define ERROR_UNKNOWN 4
#define ERROR_STACK_EMPTY 5
#define ERROR_POP 6
#define ERROR_STACK_SHORT 7
#define ERROR_OF_ZERO 8
void handle_errors(char *opcode, int error, int numline);
#endif
