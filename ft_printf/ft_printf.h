/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:07:47 by snait-ai          #+#    #+#             */
/*   Updated: 2024/12/03 10:20:24 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *frm, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_nbr(int n);
int		print_hexdec(unsigned long j, char s, int is_hexa);
int		print_unbre(unsigned int nbr);
int		print_address(void *n);

#endif
