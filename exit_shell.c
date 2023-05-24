#include "main.h"

/**
 * exit_shell - Function to exit shell
 *
 * Return: Nothing
 */
void exit_shell(void)
{
	if (!isatty(STDIN_FILENO))
		exit(EXIT_SUCCESS);
	exit(EXIT_SUCCESS);
}
