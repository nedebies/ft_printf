/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:48:34 by nesdebie          #+#    #+#             */
/*   Updated: 2023/04/14 12:52:36 by nesdebie         ###   ########.fr       */
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
	else if (!str[0])
		return (0);
	while (str[i])
		i += print_c(str[i]);
	return (i);
}
