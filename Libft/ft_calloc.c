/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <ttertrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:08:14 by ttertrai          #+#    #+#             */
/*   Updated: 2026/04/29 02:13:16 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*p;

	if (n == 0 || size == 0)
		return (malloc(0));
	if (n > SIZE_MAX / size)
		return (NULL);
	p = malloc(n * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, n * size);
	return (p);
}
