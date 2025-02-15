int main() {
    char *line = readline("Enter a line: ");
    if (line) {
        printf("You entered: %s\n", line);
        replace_current_line("This is the new line");
        free(line);
    }

    // Clear the history
    rl_clear_history();

    return 0;
}