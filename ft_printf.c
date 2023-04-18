/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:46:34 by nesdebie          #+#    #+#             */
/*   Updated: 2023/04/14 12:50:49 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_type(va_list args, const char *type)
{
	int	c;

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
