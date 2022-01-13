/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:16:12 by nedebies          #+#    #+#             */
/*   Updated: 2022/01/13 12:16:14 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i = print_s("(null)");
		return (i);
	}
	else if (str[0] == '\0')
		return (0);
	while (str[i])
		i += print_c(str[i]);
	return (i);
}
