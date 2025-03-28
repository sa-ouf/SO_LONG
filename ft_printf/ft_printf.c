/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:45:01 by snait-ai          #+#    #+#             */
/*   Updated: 2024/12/22 15:13:04 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print(va_list arg, char ch)
{
	int	n;

	n = 0;
	if (ch == 's')
		n += print_str(va_arg(arg, char *));
	else if (ch == 'c')
		n += print_char(va_arg(arg, int));
	else if (ch == 'd' || ch == 'i')
		n += print_nbr(va_arg(arg, int));
	else if (ch == 'x' || ch == 'X')
		n += print_hexdec(va_arg(arg, unsigned int), ch, 1);
	else if (ch == 'u')
		n += print_unbre(va_arg(arg, unsigned int));
	else if (ch == 'p')
		n += print_address(va_arg(arg, void *));
	else if (ch == '%')
		n += print_char('%');
	else
	{
		n += write(1, "%", 1);
		n += write(1, &ch, 1);
	}
	return (n);
}

int	ft_printf(const char *frm, ...)
{
	va_list	args;
	int		i;
	int		c;

	if (!frm)
		return (-1);
	va_start(args, frm);
	i = 0;
	c = 0;
	while (frm[i])
	{
		if (frm[i] == '%')
		{
			if (frm[i + 1] == '\0')
				return (-1);
			c += print(args, frm[i + 1]);
			i++;
		}
		else
			c += print_char(frm[i]);
		i++;
	}
	va_end(args);
	return (c);
}
