/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthevaku <pthevaku@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:10:09 by pthevaku          #+#    #+#             */
/*   Updated: 2026/05/31 11:58:53 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fk_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

static void	ft_print_u(int fd, unsigned int nb)
{
	if (nb / 10)
		ft_print_u(fd, nb / 10);
	ft_fk_putchar(fd, nb % 10 + '0');
}

int	ft_print_unsigned(int fd, unsigned int nb)
{
	int	count;

	ft_print_u(fd, nb);
	count = 1;
	while (nb / 10)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}
