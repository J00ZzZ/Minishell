#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void display_prompt(void) {
    printf("minishell> ");
}

int main(void) {
    char *line = NULL;
    size_t len = 0;

    while (1) {
        display_prompt();
        if (getline(&line, &len, stdin) == -1) {
            break; // Handle EOF or error
        }
        // Process input here
    }

    free(line);
    return 0;
}
