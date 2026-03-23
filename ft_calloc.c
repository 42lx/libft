/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:23:02 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/23 09:59:21 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_mult_overflow(size_t a, size_t b)
{
	if (b == 0)
		return (0);
	return (a > (size_t)-1 / b);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	if (ft_mult_overflow(n, size))
		return (NULL);
	res = malloc(n * size);
	if (!res)
		return (NULL);
	ft_bzero(res, n * size);
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("VAL:%zu\n", (size_t)INT_MIN);
	printf("POINTER:%p\n", ft_calloc(INT_MIN, INT_MIN));
}
*/
