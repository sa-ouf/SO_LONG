/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:44:40 by snait-ai          #+#    #+#             */
/*   Updated: 2024/12/03 08:45:44 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	int	i;

	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_nbr(-n) + 1);
	}
	if (n >= 10)
	{
		i = print_nbr(n / 10);
		return (i + print_nbr(n % 10));
	}
	else
		return (print_char(n % 10 + 48));
	return (0);
}
