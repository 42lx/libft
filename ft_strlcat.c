/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:30:45 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/25 11:52:34 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	to_copy;

	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst[dst_len] && dst_len < dst_size)
		dst_len++;
	if (dst_len >= dst_size)
		return (dst_size + src_len);
	to_copy = src_len;
	if (dst_len + src_len >= dst_size)
		to_copy = dst_size - dst_len - 1;
	ft_memcpy(dst + dst_len, src, to_copy);
	dst[dst_len + to_copy] = '\0';
	return (dst_len + src_len);
}
