/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:42:11 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 13:02:25 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s_cast;
	unsigned char		c_cast;

	i = 0;
	s_cast = s;
	c_cast = c;
	while (i < n)
	{
		if (s_cast[i] == c_cast)
			return ((void *)&s_cast[i]);
		i++;
	}
	return (NULL);
}
