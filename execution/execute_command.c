#include "execution.h"

void execute_command(char *command, char **envp)
{
	pid_t pid;
	char *args[] = {"/bin/sh", "-c", command, NULL};

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("fork");
}
