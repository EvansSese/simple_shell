#include "main.h"

/**
 * path_finder - Find the PATH
 *
 * Returns: The PATH
 */
char *path_finder()
{
	char *path = NULL;
	char *env_var;
	char path_str[] = "PATH=";
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		j = 0;
		while (env_var[j] == path_str[j])
		{
			j++;
			if (path_str[j] == '\0')
			{
				path = &env_var[j];
				break;
			}
		}
		if (path != NULL)
			break;
	}
	return (path);
}
