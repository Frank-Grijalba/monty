#include "monty.h"
/**
 * _push - function that insert new node into stack
 * @head: head of list
 * @n: number of new node
 * Return: address of new element
 */
stack_t *_push(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		handle_errors("malloc", ERROR_OF_MALLOC, 0);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (!(*head))
	{
		*head = new;
		return (*head);
	}

	while ((*head)->prev)
		*head = (*head)->prev;

	(*head)->prev = new;
	new->next = *head;
	*head = new;
	return (*head);
}
/**
 * open_file - open the monty file and read his content
 * @arg: the file to open
 * Return: Void no return
 */
void open_file(char *arg)
{
	char *oper, *values;
	size_t buffer = 0;
	unsigned int numline = 1;
	int val;

	settings.file = fopen(arg, "r");
	if (!settings.file)
		handle_errors(arg, ERROR_OPEN_FILE, numline);
	while ((getline(&settings.line, &buffer, settings.file) != EOF))
	{
		oper = strtok(settings.line, " ");
		if (*oper == '#' || *oper == '\n')
		{
			numline++;
			continue;
		}
		values = strtok(NULL, " \n");
		if (strcmp(oper, "push") == 0)
		{
			if (is_int(values) && values != NULL)
			{
			val = atoi(values);
			_push(&settings.stack, val);
			}
			else
			{
				handle_errors(arg, ERROR_USAGE, numline);
			}
		}
		else
		{
			exec_foo(&settings.stack, oper, numline);
		}
		numline++;
	}
}
/**
 * exec_foo - execute the opcode function
 * @stack: head of the stack
 * @opcode: opcode instruction
 * @numline: number of line
 */
void exec_foo(stack_t **stack, char *opcode, int numline)
{
	int i;
	char *op;
	instruction_t instructions[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{NULL, NULL}
	};
	op = strtok(opcode, " \n");

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, numline);
			return;
		}
	}
	handle_errors(opcode, ERROR_UNKNOWN, numline);
}
