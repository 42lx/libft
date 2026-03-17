/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:55:39 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/17 14:17:26 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	const char	*p1;
	const char	*p2;

	p1 = s;
	while (*p1 && ft_strchr(set, *p1))
		p1++;
	p2 = ft_strchr(s, '\0');
	while (p2 > p1 && ft_strchr(set, *p2))
		p2--;
	return (ft_substr(p1, 0, p2 - p1 + 1));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s$\n", ft_strtrim(" abc ", " "));
	printf("%s$\n", ft_strtrim("  ", " "));
}
*/
