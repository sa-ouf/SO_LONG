/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:17:31 by snait-ai          #+#    #+#             */
/*   Updated: 2024/11/14 14:01:32 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lit_len;
	size_t	i;

	i = 0;
	if (!big && len == 0)
		return (NULL);
	if (!*little)
		return ((char *)big);
	lit_len = ft_strlen(little);
	while (big[i] && lit_len + i <= len)
	{
		if (ft_strncmp(&big[i], little, lit_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
