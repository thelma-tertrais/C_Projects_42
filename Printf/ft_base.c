/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:29:48 by ttertrai          #+#    #+#             */
/*   Updated: 2026/05/06 17:22:22 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_convert(ssize_t nb, char *base, size_t len_base)
{
	char	str[20];
	int		count;
	size_t	q;
	size_t	i;

	i = 0;
	count = 0;
	if (nb == 0)
		count = count + ft_putchar_cnt(base[0]);
	while (nb != 0)
	{
		q = nb % len_base;
		str[i] = base[q];
		nb = nb / len_base;
		i++;
	}
	while (i--)
		count = count + ft_putchar_cnt(str[i]);
	return (count);
}

size_t	ft_putnbr_base(ssize_t nb, char *base, size_t len_base, char check)
{
	int	count;

	count = 0;
	if ((check == 'd' || check == 'i' || check == 'u') && nb < 0)
	{
		count = count + ft_putchar_cnt('-');
		nb = nb * (-1);
	}
	else if (check == 'p' && nb == 0)
	{
		count += ft_putstr_cnt("(nil)");
		return (count);
	}
	else if (check == 'p')
		count = count + ft_putstr_cnt("0x");
	count = count + print_convert(nb, base, len_base);
	return (count);
}
