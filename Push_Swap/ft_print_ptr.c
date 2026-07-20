/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthevaku <pthevaku@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:54:48 by pthevaku          #+#    #+#             */
/*   Updated: 2026/05/31 11:57:24 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	static_print_lower(int fd, unsigned long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb / 16)
		static_print_lower(fd, nb / 16);
	ft_putchar(fd, base[nb % 16]);
}

int	ftt_print_lower_hex(int fd, unsigned long nb)
{
	int	count;

	static_print_lower(fd, nb);
	count = 1;
	while (nb / 16)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

int	ft_print_ptr(int fd, unsigned long nb)
{
	if (nb == 0)
		return (ft_putstr(fd, "(nil)"));
	ft_putstr(fd, "0x");
	return (2 + ftt_print_lower_hex(fd, nb));
}
