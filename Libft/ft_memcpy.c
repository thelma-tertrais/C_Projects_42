/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:45:29 by ttertrai          #+#    #+#             */
/*   Updated: 2026/04/25 17:29:55 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dest1;

	if (!dest && !src)
		return (NULL);
	i = 0;
	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dest;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
