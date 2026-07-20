/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:47:33 by ttertrai          #+#    #+#             */
/*   Updated: 2026/04/27 14:11:22 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t		i;
	size_t		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_free(char **res, size_t k)
{
	while (k > 0)
		free(res[--k]);
	free(res);
}

static char	**ft_fill(char **res, char const *s, char c, size_t count)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	while (k < count)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		res[k] = ft_substr(s, i, j - i);
		if (!res[k])
		{
			ft_free(res, k);
			return (NULL);
		}
		i = j;
		k++;
	}
	res[k] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	res = malloc(sizeof (char *) * (count + 1));
	if (!res)
		return (NULL);
	return (ft_fill(res, s, c, count));
}
