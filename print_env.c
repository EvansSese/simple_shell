#include "main.h"
/**
 * print_env - Function to print env
 *
 * Return: Nothing
 */
void print_env(void)
{
	while (*environ)
	{
		size_t bytes_len = _strlen(*environ);
		write(STDOUT_FILENO, *environ, bytes_len);
		write(STDOUT_FILENO, "\n", 2);
		environ++;
	}
}
