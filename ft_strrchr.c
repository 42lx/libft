/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:18:10 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 01:28:18 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s_cast;
	char	c_cast;

	i = ft_strlen(s);
	s_cast = (char *)s;
	c_cast = (char)c;
	while (1)
	{
		if (s_cast[i] == c_cast)
			return (&s_cast[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "tripouille";

	printf("%p\n", ft_strrchr(s, 'z'));
}
*/
