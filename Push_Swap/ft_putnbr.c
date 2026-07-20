/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:01:30 by pthevaku          #+#    #+#             */
/*   Updated: 2026/06/01 10:40:21 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int fd, int nb)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar(fd, '-');
		nb = -nb;
	}
	if (nb / 10)
		ft_putnbr(fd, nb / 10);
	ft_putchar(fd, nb % 10 + '0');
}

int	ft_putnbr_count(int fd, int nb)
{
	int	count;

	ft_putnbr(fd, nb);
	if (nb == -2147483648)
		return (11);
	if (nb >= 0)
		count = 1;
	else
		count = 2;
	if (nb < 0)
		nb = -nb;
	while (nb / 10)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

int	ft_print_float(int fd, double n)
{
	int	count;
	int	integer;
	int	decimals;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar(fd, '-');
		n = -n;
	}
	integer = (int)n;
	decimals = (int)((n - (int)n) * 100 + 0.5);
	if (decimals == 100)
	{
		integer ++;
		decimals = 0;
	}
	count += ft_putnbr_count(fd, integer);
	count += ft_putchar(fd, '.');
	if (decimals < 10)
		count += ft_putchar(fd, '0');
	count += ft_putnbr_count(fd, decimals);
	count += ft_putchar(fd, '%');
	return (count);
}
