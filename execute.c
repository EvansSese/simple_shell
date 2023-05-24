#include "main.h"

/**
 * simple_execute - Executes a command without arguments
 * @tokens_arr: Array of tokens
 * @argv: Arguments array
 *
 * Return: Nothing
 */
void simple_execute(char *tokens_arr[], char *argv[])
{
	pid_t child_pid;
	int status, i = 0, j = 0, k = 0;
	char *path, *path_str, *path_arr[100], *command, *file_dir;

	path = path_finder();
	path_str = strtok(path, ":");
	while (path_str)
	{
		path_arr[j] = path_str;
		path_str = strtok(NULL, ":");
		j++;
	}
	path_arr[j] = '\0';
	while (tokens_arr[i])
	{
		if (access(tokens_arr[i], X_OK) != 0)
		{
			while (path_arr[k])
			{
				file_dir = malloc(100 * sizeof(char) + 1);
				if (file_dir == NULL)
					free(file_dir);
				_strcat(path_arr[k], tokens_arr[i], file_dir);
				if (access(file_dir, X_OK) == 0)
				{
					command = file_dir;
					break;
				}
				k++;
				free(file_dir);
			}
		}
		else
		{
			command = tokens_arr[i];
		}
		if (_strcmp(tokens_arr[i], "exit") == 0)
			exit(EXIT_SUCCESS);
		else if (_strcmp(tokens_arr[i], "env") == 0)
		{
			print_env();
			if (!isatty(STDIN_FILENO))
			{
				free(file_dir);
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				if (execve(command, tokens_arr, environ) == -1)
				{
					perror(argv[0]);
					free(file_dir);
					exit(EXIT_FAILURE);
				}
			}
			else if (child_pid < 0)
				perror(argv[0]);
			else
			{
				wait(&status);
				if (!isatty(STDIN_FILENO))
				{
					free(file_dir);
					exit(EXIT_SUCCESS);
				}
				free(file_dir);
			}
		}
		i++;
	}
}
