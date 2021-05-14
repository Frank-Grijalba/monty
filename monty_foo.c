#include "monty.h"

/**
 * _pall - prints all the elements from the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (!stack || !*stack)
		return;

	for (tmp = *stack; tmp; tmp = tmp->next)
		printf("%d\n", tmp->n);
}

/**
 * _pop - pop the top element off the stack
 * @stack: head of stack (linked list)
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (!*stack)
		handle_errors("pop", ERROR_POP, line_number);

	if (!tmp)
		handle_errors("pop", ERROR_POP, line_number);

		*stack = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = NULL;

	free(tmp);
}
/**
 * _nop - Do nothing...
 * @stack: head of stack (linked list)
 * @line_number: line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * _pint - prints the number of the head node
 * @stack: the stack
 * @line_number: line number
 * Return: None
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack || !*stack)
	{
		handle_errors("pint", ERROR_STACK_EMPTY, line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _swap - swap the top two elements
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
		handle_errors("swap", ERROR_STACK_SHORT, line_number);

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

