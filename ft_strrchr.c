/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:18:10 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/02 00:22:07 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*s)
		s++;
	while (1)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		if (p == s)
			break ;
		s--;
	}
	return (NULL);
}
