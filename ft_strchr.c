/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:58:08 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 00:47:26 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s_cast;

	i = 0;
	s_cast = (char *)s;
	while (s_cast[i])
	{
		if (s_cast[i] == c)
			return (&s_cast[i]);
		i++;
	}
	if (s_cast[i] == c)
		return (&s_cast[i]);
	return (NULL);
}
