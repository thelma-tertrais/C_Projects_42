/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:47:54 by pthevaku          #+#    #+#             */
/*   Updated: 2026/06/01 14:42:46 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_find_first_unindexed(t_list	*stack)
{
	t_node	*cur;

	cur = stack->head;
	while (cur && cur->index != -1)
		cur = cur->next;
	return (cur);
}

static t_node	*ft_find_min_unindex(t_list *stack)
{
	t_node	*cur;
	t_node	*min_node;
	long	min_val;

	min_node = ft_find_first_unindexed(stack);
	if (!min_node)
		return (NULL);
	min_val = min_node->d;
	cur = stack->head;
	while (cur)
	{
		if (cur->index == -1 && cur->d <= min_val)
		{
			min_val = cur->d;
			min_node = cur;
		}
		cur = cur->next;
	}
	return (min_node);
}

void	ft_index(t_list *stack)
{
	t_node	*min_node;
	int		i;

	i = 0;
	while (i < stack->list_size)
	{
		min_node = ft_find_min_unindex(stack);
		if (!min_node)
			break ;
		min_node->index = i;
		i++;
	}
}
