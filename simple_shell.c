#include "main.h"

char *tokens_arr[MAX_NUM_TOKENS];
int num_tokens = 0;


/**
 * tokenizer - Function to extract tokens
 * @input: Input string
 *
 * Return: Nothing;
 */
void tokenizer(char *input)
{
        char *token;

        token = strtok(input, " ");
        while (token && num_tokens < MAX_NUM_TOKENS)
        {
                tokens_arr[num_tokens] = token;
                num_tokens++;
                token = strtok(NULL, " ");
        }
        tokens_arr[num_tokens] = NULL;
}
/**
 * show_prompt - Function to show prompt if filestream is terminal
 *
 * Return: Nothing
 */
void show_prompt(void)
{
        if (isatty(STDIN_FILENO))
                write(STDIN_FILENO, "$ ", 2);
}

/**
 * handle_sig_int - Handle Ctrl + C
 * @sig: Signal int
 *
 * Return: Nothing
 */
void handle_sig_int(int sig)
{
        if (sig < 0)
                exit(EXIT_FAILURE);
}
/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument array
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
        if (argc == 1)
        {
                while (1)
                {
                        char input[MAX_INPUT_SIZE];
                        ssize_t bytes_read;
                        char *comm, *comm_arr[MAX_NUM_TOKENS];
                        int com_num = 0, j = 0;

                        show_prompt();
                        bytes_read = read(0, input, MAX_INPUT_SIZE);
                        if (bytes_read == -1)
                                perror(argv[0]);
                        input[bytes_read - 1] = '\0';
                        if (feof(stdin))
                        {
                                write(1, "\n", 2);
                                exit(EXIT_SUCCESS);
                        }
                        comm = strtok(input, "\n");
                        while (comm && com_num < MAX_NUM_TOKENS)
                        {
                                comm_arr[com_num] = comm;
                                com_num++;
                                comm = strtok(NULL, "\n");
                        }
                        comm_arr[com_num] = '\0';
                        while (comm_arr[j])
                        {
                                num_tokens = 0;
                                tokenizer(comm_arr[j]);
                                if (num_tokens == 0)
                                {
                                        exit(EXIT_SUCCESS);
                                        continue;
                                }
                                simple_execute(tokens_arr, argv);
                                j++;
                        }
                }
                exit(EXIT_SUCCESS);
        }
        return (0);
}
