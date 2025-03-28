/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:05:47 by snait-ai          #+#    #+#             */
/*   Updated: 2024/11/12 20:35:00 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chek_char(char const *se, char c)
{
	int	i;

	i = 0;
	while (se[i])
	{
		if (se[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*pt;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && chek_char(set, s1[start]) == 1)
		start++;
	while (chek_char(set, s1[end - 1]) == 1 && end > start)
		end--;
	i = 0;
	pt = (char *)malloc((end - start + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	while (start < end)
	{
		pt[i] = s1[start];
		i++;
		start++;
	}
	pt[i] = 0;
	return (pt);
}
