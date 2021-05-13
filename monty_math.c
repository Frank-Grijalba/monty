#include "monty.h"

/**
 * _add - this function executes the add opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		handle_errors("add", ERROR_STACK_SHORT, line_number);
	next = actual->next;
	next->n =  next->n + actual->n;
	_pop(stack, line_number);
}
/**
 * _sub - this function executes the sub opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		handle_errors("sub", ERROR_STACK_SHORT, line_number);
	next = actual->next;
	next->n =  next->n - actual->n;
	_pop(stack, line_number);
}
/**
 * _mul - this function executes the mul opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		handle_errors("mul", ERROR_STACK_SHORT, line_number);
	next = actual->next;
	next->n =  next->n * actual->n;
	_pop(stack, line_number);
}
/**
 * _div - this function executes the div opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		handle_errors("div", ERROR_STACK_SHORT, line_number);
	if (actual->n == 0)
		handle_errors("div", ERROR_OF_ZERO, line_number);
	next = actual->next;
	next->n =  next->n / actual->n;
	_pop(stack, line_number);
}

/**
 * _mod - this function executes the mod opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		handle_errors("mod", ERROR_STACK_SHORT, line_number);
	if (actual->n == 0)
		handle_errors("mod", ERROR_OF_ZERO, line_number);
	next = actual->next;
	next->n =  next->n % actual->n;
	_pop(stack, line_number);
}