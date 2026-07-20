/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:06:41 by ttertrai          #+#    #+#             */
/*   Updated: 2026/06/01 14:13:43 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_option_2(char **argv, int i, t_option *options)
{
	if (ft_strcmp(argv[i], "--simple") == 0)
	{
		options->simple = 1;
		i++;
	}
	else if (ft_strcmp(argv[i], "--medium") == 0)
	{
		options->medium = 1;
		i++;
	}
	else if (ft_strcmp(argv[i], "--complex") == 0)
	{
		options->complexe = 1;
		i++;
	}
	else if (ft_strcmp(argv[i], "--adaptive") == 0)
	{
		options->adaptive = 1;
		i++;
	}
	return (i);
}

int	ft_check_option(char **argv, int i, t_option *options)
{
	if (ft_strcmp(argv[i], "--bench") == 0)
	{
		options->bench = 1;
		i++;
	}
	i = ft_check_option_2(argv, i, options);
	if (ft_is_number(argv[i]) == 0)
		i = -1;
	if (!argv[i] || (argv[i] && !(argv[i + 1])))
		i = -1;
	return (i);
}

int	ft_check_after_options(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_is_number(argv[i]) == 0)
			return (0);
		i++;
	}
	return (ft_check_duplicates(argv));
}

int	ft_check_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i +1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_checker(char **argv, t_option *options)
{
	int	i;

	i = ft_check_option(argv, 1, options);
	if (i < 0)
		return (0);
	if (!ft_check_after_options(argv + i))
		return (0);
	return (i);
}
