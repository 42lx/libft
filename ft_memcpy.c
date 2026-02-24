/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:43:49 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 00:09:06 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_cast;
	unsigned char	*src_cast;

	i = 0;
	dst_cast = (unsigned char *)dst;
	src_cast = (unsigned char *)src;
	while (i < n)
	{
		dst_cast[i] = src_cast[i];
		i++;
	}
	return (dst);
}
