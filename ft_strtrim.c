/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:55:39 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/28 11:24:31 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	end = ft_strlen(s);
	while (end > start && ft_strchr(set, s[end]))
		end--;
	return (ft_substr(s, start, end - start + 1));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s$\n", ft_strtrim(" abc ", " "));
	printf("%s$\n", ft_strtrim("  ", " "));
}
*/
