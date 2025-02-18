#include "execution.h"

void	execute_command(char *command)
{
	pid_t	pid;
	char	*args[] = {"/bin/sh", "-c", command, NULL};

	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("fork");
}