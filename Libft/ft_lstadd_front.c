/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <ttertrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:12:31 by ttertrai          #+#    #+#             */
/*   Updated: 2026/05/03 18:50:39 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>
int main()
{
	t_list  *lst;

	lst = ft_lstnew("hey");
	ft_lstadd_front(&lst, lst);
	printf("%s\n", (char *)lst->content);
	printf("%s\n", (char *)lst->next->content);
}*/
