/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:50:43 by nedebies          #+#    #+#             */
/*   Updated: 2022/01/08 22:37:21 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_parse_type(va_list args, const char *type)
{
	int c;

	c = 0;
	if (*type == 'c')
		c += print_c(va_arg(args, int));
	else if (*type == 's')
		c += print_s(va_arg(args, char *));
	else if (*type == 'i' || *type == 'd')
		c += ft_check_sign_nbr(va_arg(args, int));
	else if (*type == 'u')
		c += print_nbr((unsigned int) va_arg(args, int));
	else if (*type == 'x')
		c += check_hex_ptr((unsigned int) va_arg(args, int), *type);
	else if (*type == 'X')
		c += check_hex_ptr((unsigned int) va_arg(args, int), *type);
	else if (*type == 'p')
		c += check_hex_ptr((unsigned long) va_arg(args, void *), *type);
	else if (*type == '%')
		c += print_c('%');
	else 
		return (-1);
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			cnt;
	int			ctrl;

	va_start(args, str);
	cnt = 0;
	ctrl = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ctrl = ft_parse_type(args, ++str);
			if (ctrl == -1)
				return (ctrl);
			cnt += ctrl;
		}
		else
			cnt += print_c(*str);
		str++;
	}
	va_end(args);
	return (cnt);
}
