#include "minishell.h"

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("minishell");
        }
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        perror("minishell");
    }
}

int main(int ac, char **av, char **ev)
{
    t_minis mini;

    (void)ac;
    
    (void)av;


}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        printf("minishell> ");
        read = getline(&line, &len, stdin);
        if (read == -1) {
            break;
        }

        // Remove newline character
        line[read - 1] = '\0';

        // Tokenize input
        char *args[64];
        int i = 0;
        args[i] = strtok(line, " ");
        while (args[i] != NULL) {
            args[++i] = strtok(NULL, " ");
        }

        // Execute command
        execute_command(args);
    }

    free(line);
    return 0;
}