/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:05:48 by snait-ai          #+#    #+#             */
/*   Updated: 2025/01/03 17:57:45 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (c == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_strjoin(char *my_line, char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*str;

	if (!my_line)
	{
		my_line = malloc(1);
		my_line[0] = '\0';
	}
	if (!my_line || !buffer)
		return (NULL);
	i = -1;
	x = ft_strlen(my_line) + ft_strlen(buffer);
	str = malloc(x + 1);
	if (!str)
		return (NULL);
	while (my_line[++i])
		str[i] = my_line[i];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[x] = '\0';
	free(my_line);
	return (str);
}

static char	*read_line(int fd, char *my_line)
{
	char	*buffer;
	ssize_t	nread;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nread = 1;
	while (ft_strchr(my_line, '\n') != 0 && nread != 0)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (nread == 0)
			break ;
		buffer[nread] = '\0';
		my_line = ft_strjoin(my_line, buffer);
	}
	free(buffer);
	return (my_line);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*my_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	my_line = read_line(fd, my_line);
	if (!my_line)
		return (NULL);
	str = get_my_line(my_line);
	if (!str)
	{
		free(my_line);
		my_line = NULL;
		return (NULL);
	}
	my_line = left_of_line(my_line);
	return (str);
}
