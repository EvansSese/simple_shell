#include "main.h"

/**
 * _strcat - Concatenates path and command
 * @str1: Path
 * @str2: Command
 * @file_dir: file directory
 *
 * Return: Nothing
 */

void _strcat(const char *str1, const char *str2, char *file_dir)
{
	int i = 0, j = 0;
	while (str1[i] != '\0')
	{
		file_dir[i] = str1[i];
		i++;
	}
	file_dir[i] = '/';
	i++;
	while (str2[j] != '\0')
	{
		file_dir[i] = str2[j];
		i++;
		j++;
	}
	file_dir[i] = '\0';
}
