/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthevaku <pthevaku@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:52:47 by pthevaku          #+#    #+#             */
/*   Updated: 2026/05/31 12:09:45 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fkk_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

static void	ft_print_lower(int fd, unsigned int nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb / 16)
		ft_print_lower_hex(fd, nb / 16);
	ft_fkk_putchar(fd, base[nb % 16]);
}

int	ft_print_lower_hex(int fd, unsigned int nb)
{
	int	count;

	ft_print_lower(fd, nb);
	count = 1;
	while (nb / 16)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}
