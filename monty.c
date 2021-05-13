#include "monty.h"
/**
 * main - entry point
 * @argc: count of arguments
 * @argv: Vector with arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(*(argv + 1));
    clean();
	return (EXIT_SUCCESS);
}