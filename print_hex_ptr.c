/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:07:11 by nedebies          #+#    #+#             */
/*   Updated: 2022/01/08 22:43:30 by nedebies         ###   ########.fr       */
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

int check_hex_ptr(unsigned long nb, char c)
{
	int		cnt;
	char	*str;

	cnt = 0;
	if (c == 'p')
	{
		if (nb == 0)
		{
			cnt += print_s("(nil)");
			return (cnt);
		}
		cnt += print_s("0x");
	}
	if (c == 'x' || c == 'p')
		str = ft_strdup("0123456789abcdef");
	else
		str = ft_strdup("0123456789ABCDEF");
	cnt += print_hex_p(nb, str);
	free(str);
	return (cnt);
}