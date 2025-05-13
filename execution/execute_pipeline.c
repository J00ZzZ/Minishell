/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:26:22 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/13 21:51:02 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	close_pipe(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
}

static void	wait_for_children(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void execute_pipeline(t_cmd *cmd1, t_cmd *cmd2, char **envp)
{
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1)
    {
        perror("minishell: pipe");
        return;
    }
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("minishell: fork");
        close_pipe(pipefd);
        return;
    }
    if (pid1 == 0) // Child process for the first command
    {
        close(pipefd[0]); // Close the read end of the pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the pipe
        close(pipefd[1]); // Close the write end after duplicating
        execute_external_command(cmd1, envp);
        exit(EXIT_SUCCESS); // Ensure the child process exits
    }
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("minishell: fork");
        close_pipe(pipefd);
        waitpid(pid1, NULL, 0); // Wait for the first child process
        return;
    }
    if (pid2 == 0) // Child process for the second command
    {
        close(pipefd[1]); // Close the write end of the pipe
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to the pipe
        close(pipefd[0]); // Close the read end after duplicating
        execute_external_command(cmd2, envp);
        exit(EXIT_SUCCESS); // Ensure the child process exits
    }
    // Parent process
    close_pipe(pipefd); // Close the pipe in the parent
    wait_for_children(pid1, pid2); // Wait for both child processes
}
