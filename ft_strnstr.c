/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:13:00 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/01 10:25:54 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	const char	*h;
	const char	*p;
	size_t		nlen;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	if (nlen > n)
		return (NULL);
	n -= (nlen - 1);
	while (n-- && *haystack)
	{
		h = haystack;
		p = needle;
		while (*h && *h == *p)
		{
			h++;
			p++;
		}
		if (*p == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
