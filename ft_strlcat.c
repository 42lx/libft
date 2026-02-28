/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:30:45 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/28 20:14:47 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	size_t		dlen;
	const char	*s;
	size_t		n;

	d = dst;
	s = src;
	n = dstsize;
	while (n-- && *d)
		d++;
	dlen = d - dst;
	if (dlen == dstsize)
		return (dstsize + ft_strlen(src));
	dstsize -= dlen;
	while (dstsize-- > 1 && *s)
		*d++ = *s++;
	*d = '\0';
	while (*s)
		s++;
	return (dlen + (s - src));
}
