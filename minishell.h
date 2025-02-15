#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

// Structure for the linked list node
typedef struct s_history {
    char *command;
    struct s_history *next;
} t_history;

// Function prototypes
void add_to_history(t_history **history, char *command);
void print_history(t_history *history);
void free_history(t_history *history);
void execute_command(char *command);

#endif