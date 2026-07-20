/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthevaku <pthevaku@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:22:27 by pthevaku          #+#    #+#             */
/*   Updated: 2026/05/31 12:00:27 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fku_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

static void	ft_print_upper(int fd, unsigned int nb)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb / 16)
		ft_print_upper(fd, nb / 16);
	ft_fku_putchar(fd, base[nb % 16]);
}

int	ft_print_upper_hex(int fd, unsigned int nb)
{
	int	count;

	ft_print_upper(fd, nb);
	count = 1;
	while (nb / 16)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}
