/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:38:33 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 11:38:02 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list *depart, t_list *arrivee)
{
	t_node	*tmp;

	if (!depart || depart->list_size == 0)
		return ;
	tmp = depart->head;
	depart->head = depart->head->next;
	if (depart->head)
		depart->head->prev = NULL;
	else
		depart->tail = NULL;
	depart->list_size--;
	tmp->next = arrivee->head;
	tmp->prev = NULL;
	if (arrivee->head)
		arrivee->head->prev = tmp;
	else
		arrivee->tail = tmp;
	arrivee->head = tmp;
	arrivee->list_size++;
}

void	pa(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt)
{
	push(stack_b, stack_a);
	if (opt->bench == 0)
		write(1, "pa\n", 3);
	ops->pa++;
	ops->total++;
}

void	pb(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt)
{
	push(stack_a, stack_b);
	if (opt->bench == 0)
		write(1, "pb\n", 3);
	ops->pb++;
	ops->total++;
}
