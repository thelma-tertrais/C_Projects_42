/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:57:25 by ttertrai          #+#    #+#             */
/*   Updated: 2026/04/25 17:58:09 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		end;

	end = 0;
	while (s[end])
		end++;
	while (end >= 0)
	{
		if (s[end] == (char)c)
			return ((char *)&s[end]);
		end--;
	}
	return (NULL);
}
