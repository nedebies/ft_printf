/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:51:15 by nedebies          #+#    #+#             */
/*   Updated: 2022/01/08 22:45:56 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

void	ft_putchar_fd(int c, int fd);
size_t	ft_strlen(char const *str);
char	*ft_strdup(char const *src);

int		print_c(int c);
int		print_s(char *str);
int     ft_check_sign_nbr(int i);
int	    print_nbr(unsigned int nb);
int     check_hex_ptr(unsigned long nb, char c);

#endif
