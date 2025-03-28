/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:45:30 by snait-ai          #+#    #+#             */
/*   Updated: 2024/12/03 10:45:57 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexdec(unsigned long j, char s, int is_hexa)
{
	char	*b;
	int		i;

	if (is_hexa)
		j = (unsigned int)j;
	i = 0;
	b = NULL;
	if (s == 'X')
		b = "0123456789ABCDEF";
	else if (s == 'x')
		b = "0123456789abcdef";
	if (j >= 16)
		i += print_hexdec(j / 16, s, is_hexa);
	i += print_char(b[j % 16]);
	return (i);
}
