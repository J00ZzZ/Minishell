#include "execution.h"

void execute_command(char **args, char **envp)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // Child process
        execve(args[0], args, envp);
        ft_putstr_fd("minishell: ", STDERR_FILENO);
        perror(args[0]); // Print error if execve fails
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
        				// Parent process
        wait(NULL); // Wait for the child process to finish
    else
    {
        ft_putstr_fd("minishell: ", STDERR_FILENO);
        perror("fork"); // Print error if fork fails
    }
}
