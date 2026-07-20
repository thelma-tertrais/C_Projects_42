/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:35:21 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 11:35:00 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_disorder(t_list *stack)
{
	int		mistakes;
	int		total_pairs;
	t_node	*node1;
	t_node	*node2;

	if (!stack || stack->list_size < 2)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	node1 = stack->head;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			total_pairs++;
			if (node1->d > node2->d)
				mistakes++;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	if (total_pairs == 0)
		return (0);
	return (((float)mistakes / total_pairs));
}

void	ft_link_disorder(t_list *a, t_list *b, t_operation *ops, t_option *opt)
{
	float	disorder;

	disorder = ft_disorder(a);
	if (disorder < 0.2)
		selection_sort(a, b, ops, opt);
	else if (disorder < 0.5)
		medium_sort(a, b, ops, opt);
	else
		ft_radix(a, b, ops, opt);
}
