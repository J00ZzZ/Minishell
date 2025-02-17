#include "minishell.h"

// Function to add a command to the history
void add_to_history(t_history **history, char *command) {
    t_history *new_node = malloc(sizeof(t_history));
    if (!new_node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->command = strdup(command);
    if (!new_node->command) {
        perror("strdup");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    new_node->next = *history;
    *history = new_node;
}

// Function to print the command history
void print_history(t_history *history) {
    t_history *current = history;
    while (current) {
        printf("%s\n", current->command);
        current = current->next;
    }
}

// Function to free the history linked list
void free_history(t_history *history) {
    t_history *tmp;
    while (history) {
        tmp = history;
        history = history->next;
        free(tmp->command);
        free(tmp);
    }
}

// Function to execute a command
void execute_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *args[] = {"/bin/sh", "-c", command, NULL};
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        perror("fork");
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    t_history *history = NULL;

    while (1) {
        printf("minishell> ");
        if (!fgets(input, MAX_INPUT_SIZE, stdin)) {
            break;
        }

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "history") == 0) {
            print_history(history);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            add_to_history(&history, input);
            execute_command(input);
        }
    }

    free_history(history);
    return 0;
}