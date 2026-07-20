/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:10:54 by ttertrai          #+#    #+#             */
/*   Updated: 2026/04/25 17:51:10 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	while (dst[len_dst])
		len_dst++;
	if (size <= len_dst)
	{
		i = 0;
		while (src[i])
			i++;
		return (size + i);
	}
	i = 0;
	while (src[i] && i < size - len_dst - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	while (src[i])
		i++;
	return (len_dst + i);
}
