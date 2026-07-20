/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:15:37 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 11:26:00 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// on peut manipuler les valeurs et pas les pointeurs
// pcq on reste dans la meme stack et que sa taille ne change pas

static void	swap(t_list *stack)
{
	int	tmp;

	if (!stack || stack->list_size < 2)
		return ;
	tmp = stack->head->d;
	stack->head->d = stack->head->next->d;
	stack->head->next->d = tmp;
}

void	sa(t_list *stack_a, t_operation *ops, t_option *options)
{
	swap(stack_a);
	if (options->bench == 0)
		write(1, "sa\n", 3);
	ops->sa++;
	ops->total++;
}

void	sb(t_list *stack_b, t_operation *ops, t_option *options)
{
	swap(stack_b);
	if (options->bench == 0)
		write(1, "sb\n", 3);
	ops->sb++;
	ops->total++;
}

void	ss(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt)
{
	swap(stack_a);
	swap(stack_b);
	if (opt->bench == 0)
		write(1, "ss\n", 3);
	ops->ss++;
	ops->total++;
}
