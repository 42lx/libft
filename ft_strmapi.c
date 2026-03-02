/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:12:38 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/01 12:40:44 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*p;
	unsigned int	i;

	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	p = res;
	while (*s)
		*p++ = f(i++, *s++);
	*p = '\0';
	return (res);
}
