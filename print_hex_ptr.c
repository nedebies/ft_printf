/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:48:02 by nesdebie          #+#    #+#             */
/*   Updated: 2023/04/18 13:37:59 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_p(unsigned long n, char *str)
{
	int	cnt;

	cnt = 0;
	if (n > 15)
		cnt += print_hex_p(n / 16, str);
	cnt += print_c(str[n % 16]);
	return (cnt);
}

int	check_hex_ptr(unsigned long nb, char c)
{
	int		cnt;

	cnt = 0;
	if (c == 'p')
	{
		if (nb == 0)
		{
			cnt += print_s("0x0");
			return (cnt);
		}
		cnt += print_s("0x");
	}
	if (c == 'x' || c == 'p')
		cnt += print_hex_p(nb, "0123456789abcdef");
	else
		cnt += print_hex_p(nb, "0123456789ABCDEF");
	return (cnt);
}
