/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:06:16 by snait-ai          #+#    #+#             */
/*   Updated: 2024/12/28 10:21:50 by snait-ai         ###   ########.fr       */
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

char	*get_my_line(char *my_line)
{
	int		i;
	char	*stor_line;

	i = 0;
	if (!my_line[i])
		return (NULL);
	while (my_line[i] && my_line[i] != '\n')
		i++;
	stor_line = malloc(i + 2);
	if (!stor_line)
		return (NULL);
	i = 0;
	while (my_line[i] && my_line[i] != '\n')
	{
		stor_line[i] = my_line[i];
		i++;
	}
	stor_line[i] = '\0';
	return (stor_line);
}

char	*left_of_line(char *my_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (my_line[i] && my_line[i] != '\n')
		i++;
	if (!my_line[i])
	{
		free(my_line);
		return (NULL);
	}
	str = malloc(ft_strlen(my_line) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (my_line[i])
		str[j++] = my_line[i++];
	str[j] = '\0';
	free(my_line);
	return (str);
}
