/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:18:10 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 14:11:22 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c_cast;

	i = ft_strlen(s);
	c_cast = c;
	while (1)
	{
		if (s[i] == c_cast)
			return ((char *)&s[i]);
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
