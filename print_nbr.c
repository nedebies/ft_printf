/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:48:20 by nesdebie          #+#    #+#             */
/*   Updated: 2023/04/05 11:50:32 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(unsigned int n)
{
	int		print;

	print = 0;
	if (n > 9)
		print += print_nbr(n / 10);
	print += print_c((char)(n % 10 + '0'));
	return (print);
}

int	ft_check_sign_nbr(int n)
{
	unsigned int	nb;
	int				print;

	print = 0;
	if (n < 0)
	{
		print += print_c('-');
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	print = print + print_nbr(nb);
	return (print);
}