/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:02:21 by snait-ai          #+#    #+#             */
/*   Updated: 2024/11/13 12:41:15 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			return ((char *)&str[i]);
		i++;
	}
	if (search == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
