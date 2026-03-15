/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:30:45 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/15 16:09:29 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*p;

	p = s;
	while (maxlen-- && *p)
		p++;
	return (p - s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		dlen;

	dlen = ft_strnlen(dst, dstsize);
	if (dlen == dstsize)
		return (dstsize + ft_strlen(src));
	d = dst + dlen;
	s = src;
	while (dstsize-- > dlen + 1 && *s)
		*d++ = *s++;
	*d = '\0';
	while (*s)
		s++;
	return (dlen + (s - src));
}
