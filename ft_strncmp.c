/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:23:45 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/04/03 19:23:20 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while (n-- && (*s1 || *s2))
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
			return (c1 - c2);
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*cmp;
	int		len;

	str = "libft-test";
	len = strlen(str);
	cmp = calloc(10, 1);
	strlcpy(cmp, "libft", 10);
	printf("str:\"%s\"; std:%d; ft:%d\n", cmp, strncmp(str, cmp, len),
		ft_strncmp(str, cmp, len));
	*(cmp + 5) = CHAR_MIN;
	printf("str:\"%s\"; std:%d; ft:%d\n", cmp, strncmp(str, cmp, len),
		ft_strncmp(str, cmp, len));
	*(cmp + 5) = -42;
	printf("str:\"%s\"; std:%d; ft:%d\n", cmp, strncmp(str, cmp, len),
		ft_strncmp(str, cmp, len));
}
*/
