#include "parsing.h"

char	*read_input(void)
{
	char	buffer[READ_BUFFER_SIZE];
	char	*input;
	ssize_t	bytes_read;

	input = NULL;
	while ((bytes_read = read(STDIN_FILENO, buffer, READ_BUFFER_SIZE - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		input = ft_strjoin_free(input, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (input && ft_strlen(input) > 0)
		input[ft_strlen(input) - 1] = '\0';
	return (input);
}