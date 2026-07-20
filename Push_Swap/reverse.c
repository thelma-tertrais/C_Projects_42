/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:46:17 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 14:05:38 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_list *stack)
{
	t_node	*tmp;

	if (!stack || stack->list_size < 2)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->next = stack->head;
	tmp->prev = NULL;
	stack->head->prev = tmp;
	stack->head = tmp;
}

void	rra(t_list *stack_a, t_operation *ops, t_option *options)
{
	reverse(stack_a);
	if (options->bench == 0)
		write(1, "rra\n", 4);
	ops->rra++;
	ops->total++;
}

void	rrb(t_list *stack_b, t_operation *ops, t_option *options)
{
	reverse(stack_b);
	if (options->bench == 0)
		write(1, "rrb\n", 4);
	ops->rrb++;
	ops->total++;
}

void	rrr(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt)
{
	reverse(stack_a);
	reverse(stack_b);
	if (opt->bench == 0)
		write(1, "rrr\n", 4);
	ops->rrr++;
	ops->total++;
}
