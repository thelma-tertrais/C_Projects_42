/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:35:42 by ttertrai          #+#    #+#             */
/*   Updated: 2026/04/25 18:03:30 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	start;
	size_t	len_little;

	len_little = 0;
	while (little[len_little])
		len_little++;
	if (len_little == 0)
		return ((char *)big);
	start = 0;
	while (start < len && big[start])
	{
		i = 0;
		while (start + i < len && big[start + i] == little[i])
			i++;
		if (i == len_little)
			return ((char *)&big[start]);
		start++;
	}
	return (NULL);
}
