#include "main.h"

/**
 * _strcat - Concatenates path and command
 * @file_path: Path
 * @com: Command
 *
 * Return: Returns full path
 */

void _strcat(char *file_path, char *com, char *file_dir)
{
	int i = 0, j = 0, k = 0;

	while (file_path[i])
	{
		file_dir[k] = file_path[i];
		i++;
		k++;
	}
	file_dir[k] = '/';
	k++;
	while (com[j])
	{
		file_dir[k] = com[j];
		j++;
		k++;
	}
}
