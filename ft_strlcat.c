/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:30:45 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/18 13:26:16 by ohaponiu         ###   ########.fr       */
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
	size_t		dlen;

	dlen = ft_strnlen(dst, dstsize);
	if (dlen == dstsize)
		return (dstsize + ft_strlen(src));
	return (dlen + ft_strlcpy(dst + dlen, src, dstsize - dlen));
}
