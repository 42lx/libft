/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:43:40 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/02 00:47:27 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	ressize;

	ressize = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(ressize);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ressize);
	ft_strlcat(res, s2, ressize);
	return (res);
}
