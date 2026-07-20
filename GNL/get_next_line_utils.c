/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:21:42 by ttertrai          #+#    #+#             */
/*   Updated: 2026/05/12 11:29:28 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '\n')
			return (1);
		i--;
	}
	return (0);
}

void	*ft_memcpy(void *s1, void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str2);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		len1;
	int		len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, str1, len1);
	ft_memcpy(res + len1, str2, len2);
	res[len1 + len2] = '\0';
	return (res);
}
