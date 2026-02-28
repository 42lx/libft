/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:16:11 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/28 19:58:13 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;

	s = src;
	if (dstsize > 0)
	{
		d = dst;
		while (dstsize-- > 1 && *s)
			*d++ = *s++;
		*d = '\0';
	}
	while (*s)
		s++;
	return (s - src);
}
