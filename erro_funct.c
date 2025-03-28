/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:43:26 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/25 15:44:14 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_check(char **map, int x)
{
	if (x == 0)
	{
		ft_printf("Error\nMap is not enclosed by walls\n");
		free_map(map);
	}
	else if (x == 1)
	{
		ft_printf("Error\nMap is not rectangular\n");
		free_map(map);
	}
	else if (x == 2)
	{
		ft_printf("Error\nChars is not valid\n");
		free_map(map);
	}
	else if (x == 3)
	{
		ft_printf("Error\nEmpty map\n");
		free_map(map);
	}
	exit(1);
}

void	free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
