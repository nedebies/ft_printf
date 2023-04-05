/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:48:02 by nesdebie          #+#    #+#             */
/*   Updated: 2023/04/05 11:50:16 by nesdebie         ###   ########.fr       */
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