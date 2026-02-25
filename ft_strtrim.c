/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:55:39 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/25 13:25:16 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	beg;
	size_t	end;
	size_t	len;
	char	*s2;

	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	end = ft_strlen(s1);
	while (end > beg && ft_strchr(set, s1[end]))
		end--;
	len = end - beg + 1;
	s2 = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[beg + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strtrim(" abc ", " "));
}
*/
