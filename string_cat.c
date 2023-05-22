#include "main.h"
/**
 * _strcat - Concatenates path and command
 * @file_path: Path
 * @com: Command
 *
 * Return: Returns full path
 */
char *_strcat(char *file_path, char *com)
{
        char *file_dir = malloc(100 * sizeof(char) + 1);
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
        return (file_dir);
}
