/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:36:17 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/02 13:53:39 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**head;
	t_list	*node;
	t_list	*newnode;

	head = ft_calloc(1, sizeof(t_list *));
	node = lst;
	while (node)
	{
		newnode = ft_lstnew(f(node->content));
		if (!newnode)
		{
			ft_lstclear(head, del);
			return (NULL);
		}
		ft_lstadd_back(head, newnode);
		node = node->next;
	}
	return (*head);
}
