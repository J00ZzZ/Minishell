/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:32:48 by hang              #+#    #+#             */
/*   Updated: 2025/02/18 02:42:10 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*readnjoin(int fd, char *fd_str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(fd_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		fd_str = ft_strjoin_free(fd_str, buff);
	}
	free(buff);
	return (fd_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*fd_str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fd_str[fd] = readnjoin(fd, fd_str[fd]);
	if (!fd_str[fd])
		return (NULL);
	line = cleanline(fd_str[fd]);
	fd_str[fd] = delete_upto_nl(fd_str[fd]);
	return (line);
}
