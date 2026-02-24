/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:58:08 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 11:24:21 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c_cast;

	i = 0;
	c_cast = (char)c;
	while (s[i])
	{
		if (s[i] == c_cast)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c_cast)
		return ((char *)&s[i]);
	return (NULL);
}
