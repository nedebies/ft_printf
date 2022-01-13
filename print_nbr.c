/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:57:30 by nedebies          #+#    #+#             */
/*   Updated: 2022/01/08 22:35:56 by nedebies         ###   ########.fr       */
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