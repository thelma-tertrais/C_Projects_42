/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:50:47 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 14:22:17 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strategy(t_option *options)
{
	if (options->simple)
		ft_printf(2, "[bench] strategy:  Simple    / O(n^2)\n");
	else if (options->medium)
		ft_printf(2, "[bench] strategy:  Medium    / O(n*sqrt(n))\n");
	else if (options->complexe)
		ft_printf(2, "[bench] strategy:  Complex   / O(n log n)\n");
	else
	{
		if (options->disorder_value < 0.2)
			ft_printf(2, "[bench] strategy:  Adaptive  / O(n^2)\n");
		else if (options->disorder_value < 0.5)
			ft_printf(2, "[bench] strategy:  Adaptive  / O(n*sqrt(n))\n");
		else
			ft_printf(2, "[bench] strategy:  Adaptive  / O(n log n)\n");
	}
}

void	ft_bench(t_option *options, t_operation *ops)
{
	ft_printf(2, "[bench] disorder:  %f\n", options->disorder_value);
	ft_strategy(options);
	ft_printf(2, "[bench] total_ops:  %d\n", ops->total);
	ft_printf(2, "sa:  %d  sb:  %d  ", ops->sa, ops->sb);
	ft_printf(2, "ss:  %d  pa:  %d  pb:  %d\n", ops->ss, ops->pa, ops->pb);
	ft_printf(2, "ra:  %d  rb:  %d  rr:  %d  ", ops->ra, ops->rb, ops->rr);
	ft_printf(2, "rra:  %d  rrb:  %d  ", ops->rra, ops->rrb);
	ft_printf(2, "rrr:  %d\n", ops->rrr);
}

void	choose_option(t_option *opt, t_list *a, t_list *b, t_operation *ops)
{
	if (opt->simple == 1)
		selection_sort(a, b, ops, opt);
	else if (opt->medium == 1)
		medium_sort(a, b, ops, opt);
	else if (opt->complexe == 1)
		ft_radix(a, b, ops, opt);
	else
		ft_link_disorder(a, b, ops, opt);
	if (opt->bench == 1)
		ft_bench(opt, ops);
}
