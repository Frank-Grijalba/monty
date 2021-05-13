#include "monty.h"
/**
 * clean - close the fopen and free the line of the getline
 * Return: void
 */
void clean(void)
{
	fclose(settings.file);
	free(settings.line);
}
/**
 * is_int - check if the string is a number
 * @s: string
 * Return: 1 if is number digit
 * if not, 0 is returned.
 */
int is_int(char *s)
{
	char *aux = s;

	if (s == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if (*aux < '0' || *aux > '9')
			return (0);
	}
	return (1);
}
