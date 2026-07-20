/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:17:26 by pthevaku          #+#    #+#             */
/*   Updated: 2026/06/01 12:26:07 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_bits(int nb)
{
	int	total_bits;

	total_bits = 0;
	while (nb >> total_bits)
		total_bits++;
	return (total_bits);
}

void	ft_radix(t_list *a, t_list *b, t_operation *ops, t_option *opt)
{
	int	total_bits;
	int	bits;
	int	size;
	int	i;

	if (ft_is_sorted(a))
		return ;
	total_bits = ft_count_bits(a->list_size -1);
	bits = 0;
	while (bits < total_bits)
	{
		size = a->list_size;
		i = 0;
		while (i < size)
		{
			if ((a->head->index >> bits) & 1)
				ra(a, ops, opt);
			else
				pb(a, b, ops, opt);
			i++;
		}
		while (b->list_size > 0)
			pa(a, b, ops, opt);
		bits++;
	}
}
