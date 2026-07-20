/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:55:42 by pthevaku          #+#    #+#             */
/*   Updated: 2026/06/01 15:18:24 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ops(t_operation *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->total = 0;
}

void	init_option(t_option *options)
{
	options->disorder_value = 0.0;
	options->bench = 0;
	options->medium = 0;
	options->simple = 0;
	options->adaptive = 0;
	options->complexe = 0;
}
