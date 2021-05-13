#include "monty.h"

void handle_errors(char *opcode,int error, int numline)
{
	if (error == 1)
	{	dprintf(STDERR_FILENO, "L%d: usage: push integer\n", numline);
		clean();
		exit(EXIT_FAILURE);
	}
	if (error == 2)
	{	dprintf(STDERR_FILENO, "Error: Can't open file %s\n", opcode);
		exit(EXIT_FAILURE);
	}
	if (error == 3)
	{	dprintf(STDERR_FILENO, "Error: %s failed\n", opcode);
		clean();
		exit(EXIT_FAILURE);
	}
    if (error == 4)
	{	dprintf(STDERR_FILENO,
		"L%d: unknown instruction %s\n", numline, opcode);
        clean();
        exit(EXIT_FAILURE);
    }
	if (error == 5)
	{	dprintf(STDERR_FILENO, "L%u: can't %s, stack empty\n", numline, opcode);
		clean();
		exit(EXIT_FAILURE);
	}
    if (error == 6)
	{	dprintf(STDERR_FILENO, "L%u: can't %s an empty stack\n", numline, opcode);
		clean();
		exit(EXIT_FAILURE);
	}
	if (error == 7)
	{	dprintf(STDERR_FILENO, 	"L%u: can't %s, stack too short\n", numline, opcode);
		clean();
		exit(EXIT_FAILURE);
	}
	if (error == 8)
	{	dprintf(STDERR_FILENO,  "L%u: division by zero\n", numline);
		clean();
		exit(EXIT_FAILURE);
	}
}