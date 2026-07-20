/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthevaku <pthevaku@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:44:06 by pthevaku          #+#    #+#             */
/*   Updated: 2026/05/31 12:04:22 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_real_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

int	ft_putstr(int fd, char *str)
{
	int	i;
	int	count;

	if (str == NULL)
		return (ft_putstr(fd, "(null)"));
	i = 0;
	count = 0;
	while (str[i])
	{
		ft_real_putchar(fd, str[i]);
		count++;
		i++;
	}
	return (count);
}
