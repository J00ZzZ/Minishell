#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"


void	execute_command(char *command, char** envp);

#endif