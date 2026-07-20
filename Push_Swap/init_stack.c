/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:08:54 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 12:08:00 by pthevaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(long nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->d = nb;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_node **stack, t_node *new)
{
	t_node	*temp;
	t_node	*prev;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	prev = temp;
	temp->next = new;
	if (temp->next)
		temp = temp->next;
	if (prev != temp)
		temp->prev = prev;
}

t_list	*ft_init_stack(int i, char **argv, int start, t_option *options)
{
	t_list	*stack_x;

	stack_x = malloc(sizeof(t_list));
	if (!stack_x)
		return (NULL);
	stack_x->head = NULL;
	stack_x->tail = NULL;
	stack_x->list_size = 0;
	if (i == 1)
	{
		stack_x = ft_create_stack_a_modif(argv, stack_x, start);
		ft_index(stack_x);
		options->disorder_value = ft_disorder(stack_x);
	}
	return (stack_x);
}

t_list	*ft_create_stack_a_modif(char **argv, t_list *stack_list, int start)
{
	int			i;
	t_node		*stack;
	t_node		*new;
	t_node		*temp;

	stack = NULL;
	i = start;
	while (argv[i])
	{
		new = ft_new_node(ft_atol(argv[i]));
		ft_lstadd_back(&stack, new);
		stack_list->list_size = stack_list->list_size + 1;
		i++;
	}
	temp = stack;
	while (temp->next)
		temp = temp->next;
	stack_list->head = stack;
	stack_list->tail = temp;
	return (stack_list);
}

int	ft_strcmp(char *str, char *option)
{
	int	i;

	i = 0;
	while (str[i] && option[i] && str[i] == option[i])
		i++;
	return (str[i] - option[i]);
}
