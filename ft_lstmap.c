/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:36:17 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/19 20:55:19 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*node;
	void	*cont;

	head = NULL;
	tail = NULL;
	while (lst)
	{
		cont = f(lst->content);
		node = ft_lstnew(cont);
		if (!node)
		{
			del(cont);
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = node;
		else
			tail->next = node;
		tail = node;
		lst = lst->next;
	}
	return (head);
}
