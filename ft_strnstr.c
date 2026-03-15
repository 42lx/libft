/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:13:00 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/15 15:51:18 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	while (n-- >= nlen && *haystack)
	{
		if (!ft_strncmp(haystack, needle, nlen))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*bg;
	char	*ll;
	int		len;

	bg = "mapman";
	ll = "apm";
	len = 3;
	printf("%s\n", ft_strnstr(bg, ll, len));
}
*/
