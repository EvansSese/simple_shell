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
        char *path, *path_str, *path_arr[100], *file_dir, *command;

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
                                file_dir = _strcat(path_arr[k], tokens_arr[i]);
                                if (access(file_dir, X_OK) == 0)
                                {
                                        command = file_dir;
                                        break;
                                }
                                k++;
                        }
                }
                else
                {
                        command = tokens_arr[i];
                }
                if (_strcmp(tokens_arr[i], "exit") == 0)
                        exit(EXIT_SUCCESS);
                else
                {
                    child_pid = fork();
                    if (child_pid == 0)
                    {
                            if (execve(command, tokens_arr, environ) == -1)
                            {
                                    perror(argv[0]);
                                    exit(EXIT_FAILURE);
                            }
                    }
                    else if (child_pid < 0)
                            perror(argv[0]);
                    else
                    {
                            wait(&status);
                            if (!isatty(STDIN_FILENO))
                                    exit(EXIT_SUCCESS);
                    }
                }
                i++;
        }
}
