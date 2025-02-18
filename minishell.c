#include "minishell.h"

// Custom function to read input using read()
char *read_input(void) 
{
    char buffer[READ_BUFFER_SIZE];
    char *input = NULL;
    ssize_t bytes_read;

    while ((bytes_read = read(STDIN_FILENO, buffer, READ_BUFFER_SIZE - 1)) > 0) 
    {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        input = ft_strjoin_free(input, buffer); // Concatenate and free old input

        if (ft_strchr(buffer, '\n'))  // Stop reading if newline is found
            break;
    }

    if (input && ft_strlen(input) > 0)
        input[ft_strlen(input) - 1] = '\0'; // Remove the newline character
    return input;
}



// Function to add a command to the history
void add_to_history(t_history **history, char *command) 
{
    t_history *new_node = (t_history *)ft_calloc(1, sizeof(t_history));
    if (!new_node) 
    {
        perror("ft_calloc");
        exit(EXIT_FAILURE);
    }
    new_node->command = ft_strdup(command); // Use ft_strdup from libft
    if (!new_node->command) 
    {
        perror("ft_strdup");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;

    if (*history == NULL) 
        *history = new_node; // If the list is empty, this is the first node
    else 
    {
        t_history *current = *history;
        while (current->next != NULL)
            current = current->next; // Traverse to the end of the list
        current->next = new_node; // Append the new node
    }
}

// Function to print the command history
void print_history(t_history *history) 
{
    t_history *current = history;
    int index = 1;
    while (current) 
    {
        ft_printf("%d: %s\n", index, current->command); // Use ft_printf from libft
        current = current->next;
        index++;
    }
}

// Function to free the history linked list
void free_history(t_history *history) 
{
    t_history *tmp;
    while (history) 
    {
        tmp = history;
        history = history->next;
        free(tmp->command); // Use ft_free from libft
        free(tmp); // Use ft_free from libft
    }
}

// Function to execute a command
void execute_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) 
    {
        // Child process
        char *args[] = {"/bin/sh", "-c", command, NULL};
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } 
    else if (pid > 0) // Parent process
        wait(NULL);
    else 
        perror("fork");
}

int main() 
{
    char *input;
    t_history *history = NULL;

    while (1) 
    {
        ft_printf("minishell> "); // Use ft_printf from libft
        input = read_input(); // Use custom input reader
        if (!input)
            break;
        if (ft_strncmp(input, "history", 7) == 0) // Use ft_strncmp from libft
            print_history(history);
        else if (ft_strncmp(input, "exit", 4) == 0) // Use ft_strcmp from libft
        {
            free(input);
            break;
        } 
        else if (ft_strlen(input) > 0) // Use ft_strlen from libft
        {
            add_to_history(&history, input);
            execute_command(input);
        }
        free(input); // Free the input after processing
    }
    free_history(history);
    return 0;
}
