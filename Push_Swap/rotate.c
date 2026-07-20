/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:23:31 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 12:21:32 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list *stack)
{
	t_node	*tmp;

	if (!stack || stack->list_size < 2)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	tmp->prev = stack->tail;
	tmp->next = NULL;
	stack->tail->next = tmp;
	stack->tail = tmp;
}

void	ra(t_list *stack_a, t_operation *ops, t_option *options)
{
	rotate(stack_a);
	if (options->bench == 0)
		write(1, "ra\n", 3);
	ops->ra++;
	ops->total++;
}

void	rb(t_list *stack_b, t_operation *ops, t_option *options)
{
	rotate(stack_b);
	if (options->bench == 0)
		write(1, "rb\n", 3);
	ops->rb++;
	ops->total++;
}

void	rr(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt)
{
	rotate(stack_a);
	rotate(stack_b);
	if (opt->bench == 0)
		write(1, "rr\n", 3);
	ops->rr++;
	ops->total++;
}
