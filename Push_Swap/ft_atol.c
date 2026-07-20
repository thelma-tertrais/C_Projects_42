/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:10:59 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 11:45:22 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *argv)
{
	int		i;
	long	n;

	i = 0;
	if (argv[i] == '-' && (argv[1] >= '0' && argv[1] <= '9'))
	{
		if (argv[1] >= '0' && argv[1] <= '9')
			i++;
		else
			return (0);
	}
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	n = ft_atol(argv);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	int		negatif;
	long	res;

	negatif = 1;
	i = 0;
	if (str[i] == '-')
	{
		negatif = negatif * (-1);
		i++;
	}
	res = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res = res * negatif;
	return (res);
}
