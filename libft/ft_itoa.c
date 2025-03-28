/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:09:17 by snait-ai          #+#    #+#             */
/*   Updated: 2024/10/29 20:54:26 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_int(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*chek_int(int x, size_t lenght)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[lenght] = '\0';
	x = 147483648;
	while (x > 0)
	{
		str[--lenght] = x % 10 + 48;
		x /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*ptr;

	i = len_int(n);
	if (n == -2147483648)
		return (chek_int(n, i));
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (n == 0)
		ptr[0] = '0';
	else if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		ptr[--i] = n % 10 + 48;
		n /= 10;
	}
	return (ptr);
}
