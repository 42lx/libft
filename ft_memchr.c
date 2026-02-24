/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:42:11 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 00:48:51 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cast;

	i = 0;
	s_cast = (unsigned char *)s;
	while (i < n)
	{
		if (s_cast[i] == c)
			return ((void *)&s_cast[i]);
		i++;
	}
	return (NULL);
}
