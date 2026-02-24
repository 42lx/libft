/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:57:23 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 00:12:25 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_cast;
	unsigned char	*src_cast;

	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		dst_cast = (unsigned char *)dst;
		src_cast = (unsigned char *)src;
		while (n > 0)
		{
			dst_cast[n - 1] = src_cast[n - 1];
			n--;
		}
	}
	return (dst);
}
