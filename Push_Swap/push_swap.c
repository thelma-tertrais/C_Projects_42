/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:11:33 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 15:25:48 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *stack_a)
{
	t_node	*temp;

	temp = stack_a->head;
	while (temp)
	{
		if (temp->next)
		{
			if (temp->next->index < temp->index)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

void	ft_free_stack(t_list *stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack)
		return ;
	cur = stack->head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_operation	ops;
	t_option	options;

	if (argc < 2)
		return (1);
	init_option(&options);
	if (!ft_checker(argv, &options))
		return (ft_printf(2, "Error\n"));
	stack_a = ft_init_stack(1, argv, ft_checker(argv, &options), &options);
	stack_b = ft_init_stack(0, argv, 0, &options);
	init_ops(&ops);
	choose_option(&options, stack_a, stack_b, &ops);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
