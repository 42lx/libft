/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:23:02 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/28 11:09:42 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_mult_overflow(size_t a, size_t b)
{
	if (b == 0)
		return (0);
	return (a > SIZE_MAX / b);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (ft_mult_overflow(n, size))
		return (NULL);
	if (n == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("VAL:%zu\n", (size_t)INT_MIN);
	printf("POINTER:%p\n", ft_calloc(INT_MIN, INT_MIN));
}
*/
