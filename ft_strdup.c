/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:33:38 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/30 00:14:30 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s, len + 1);
	return (res);
}
