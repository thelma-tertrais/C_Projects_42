/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:48:23 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 11:43:52 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int x)
{
	int	i;

	i = 0;
	while (i * i < x)
		i++;
	return (i);
}

static void	push_chunks(t_list *a, t_list *b, t_operation *ops, t_option *opt)
{
	int	chunk_size;
	int	seuil;
	int	pushed;

	chunk_size = (ft_sqrt(a->list_size) + 1) * 5 / 2;
	seuil = chunk_size;
	pushed = 0;
	while (a->list_size)
	{
		if (!a->head)
			break ;
		if (a->head->index < seuil)
		{
			pb(a, b, ops, opt);
			pushed++;
			if (b->head && b->head->index < (seuil - chunk_size / 2))
				rb(b, ops, opt);
			if (pushed >= seuil)
				seuil += chunk_size;
		}
		else
			ra(a, ops, opt);
	}
}

int	get_position_index(t_list *stack_b, int target)
{
	t_node	*tmp;
	int		pos;

	tmp = stack_b->head;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == target)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

static void	move_to_top(t_list *b, int pos, t_operation *ops, t_option *opt)
{
	if (pos < 0 || pos >= b->list_size)
		return ;
	if (pos <= b->list_size / 2)
	{
		while (pos-- > 0)
			rb(b, ops, opt);
	}
	else
	{
		pos = b->list_size - pos;
		while (pos-- > 0)
			rrb(b, ops, opt);
	}
}

void	medium_sort(t_list *a, t_list *b, t_operation *ops, t_option *opt)
{
	int	pos;

	if (ft_is_sorted(a))
		return ;
	push_chunks(a, b, ops, opt);
	while (b->list_size > 0)
	{
		pos = get_position_index(b, b->list_size - 1);
		if (pos == -1)
			break ;
		move_to_top(b, pos, ops, opt);
		pa(a, b, ops, opt);
	}
}
