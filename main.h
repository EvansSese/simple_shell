#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

extern char **environ;

void tokenizer(char *input);
void show_prompt(void);
void handle_sig_int(int sig);
void simple_execute(char *tokens_arr[], char *argv[]);
char *path_finder();
char *_strcat(char *file_path, char *com);
int _strcmp(const char *str1, const char *str2);
void print_env(void);
int _strlen(char *str);
void exit_shell(void);

#endif
