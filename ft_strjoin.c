/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:43:40 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/25 11:52:59 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	res_size;

	res_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(res_size);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, res_size);
	ft_strlcat(res, s2, res_size);
	return (res);
}
