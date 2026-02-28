/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:13:00 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/28 21:21:23 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	const char	*p1;
	const char	*p2;
	size_t		left;

	if (*needle == '\0')
		return ((char *)haystack);
	while (n && *haystack)
	{
		p1 = haystack;
		p2 = needle;
		left = n;
		while (left-- && *p1 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
