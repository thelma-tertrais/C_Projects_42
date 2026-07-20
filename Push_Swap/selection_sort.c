/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:50:27 by pthevaku          #+#    #+#             */
/*   Updated: 2026/06/01 12:29:21 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_list *a, t_list *b, t_operation *ops, t_option *opt)
{
	int	i;

	if (ft_is_sorted(a))
		return ;
	i = 0;
	while (a->list_size > 0)
	{
		if (a->head->index == i)
		{
			pb(a, b, ops, opt);
			i++;
		}
		else
			ra(a, ops, opt);
	}
	while (b->list_size > 0)
		pa(a, b, ops, opt);
}
