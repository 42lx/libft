/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:18:10 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 00:20:45 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s_cast;

	i = ft_strlen(s);
	s_cast = (char *)s;
	while (i >= 0)
	{
		if (s[i] == c)
			return (s_cast + i);
		i--;
	}
	return (NULL);
}
