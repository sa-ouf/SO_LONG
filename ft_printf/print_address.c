/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:43:35 by snait-ai          #+#    #+#             */
/*   Updated: 2024/12/03 08:42:39 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_address(void *n)
{
	int	count;

	count = 0;
	if ((unsigned long)n == 0)
		return (write(1, "(nil)", 5));
	count += print_str("0x");
	count += print_hexdec((unsigned long)n, 'x', 0);
	return (count);
}
