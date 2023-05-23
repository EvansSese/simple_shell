#include "main.h"
/**
 * _strlen - Function to count len of string
 * @str: String param
 *
 * Return: Length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
