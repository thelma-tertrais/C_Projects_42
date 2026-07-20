/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:35:28 by pthevaku          #+#    #+#             */
/*   Updated: 2026/06/01 14:43:26 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				d;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}			t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		list_size;
}		t_list;

typedef struct s_operation
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}		t_operation;

typedef struct s_option
{
	float	disorder_value;
	int		bench;
	int		simple;
	int		medium;
	int		complexe;
	int		adaptive;
}		t_option;

//disorder
float	ft_disorder(t_list *stack);
void	ft_link_disorder(t_list *a, t_list *b, t_operation *ops, t_option *opt);

void	ft_index(t_list *stack);
void	init_option(t_option *options);

void	init_ops(t_operation *ops);
void	choose_option(t_option *opt, t_list *a, t_list *b, t_operation *ops);

//parsing
int		ft_strcmp(char *str, char *option);
int		ft_is_number(char *argv);
int		ft_check_duplicates(char **argv);
int		ft_check_after_options(char **argv);
int		ft_check_option(char **argv, int i, t_option *options);
int		ft_checker(char **argv, t_option *options);
long	ft_atol(char *str);
t_node	*ft_new_node(long nb);
void	ft_lstadd_back(t_node **stack, t_node *new);
t_list	*ft_init_stack(int i, char **argv, int start, t_option *options);
t_list	*ft_create_stack_a_modif(char **argv, t_list *stack_list, int start);

// algos
void	selection_sort(t_list *a, t_list *b, t_operation *ops, t_option *opt);
void	medium_sort(t_list *a, t_list *b, t_operation *ops, t_option *opt);
void	ft_radix(t_list *a, t_list *b, t_operation *ops, t_option *opt);

//utilitaire algos
int		ft_is_sorted(t_list *stack_a);

//operations
void	pa(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt);
void	pb(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt);
void	rra(t_list *stack_a, t_operation *ops, t_option *options);
void	rrb(t_list *stack_b, t_operation *ops, t_option *options);
void	rrr(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt);
void	ra(t_list *stack_a, t_operation *ops, t_option *options);
void	rb(t_list *stack_b, t_operation *ops, t_option *options);
void	rr(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt);
void	sa(t_list *stack_a, t_operation *ops, t_option *options);
void	sb(t_list *stack_b, t_operation *ops, t_option *options);
void	ss(t_list *stack_a, t_list *stack_b, t_operation *ops, t_option *opt);

//bench
void	ft_bench(t_option *options, t_operation *ops);
#endif
