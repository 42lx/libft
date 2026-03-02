/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:20:52 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/02 13:29:04 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*prev;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		prev = node;
		node = node->next;
		ft_lstdelone(prev, del);
	}
	*lst = NULL;
}
