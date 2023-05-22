#include "main.h"
/**
 * _strcmp - Function to compare two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: 0 if successful, -1 failure
 */
int _strcmp(const char *str1, const char *str2)
{
        int i = 0;

        while (str1[i] != '\0' && str2[i] != '\0')
        {
                if (str1[i] != str2[i])
                        return (-1);
                i++;
        }
        if (str1[i] == '\0' && str2[i] == '\0')
                return (0);
        return (-1);
}
