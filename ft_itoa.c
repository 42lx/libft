/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:22:06 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/19 20:43:03 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_ndigits(int n)
{
	size_t	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_rec(long n, char *end)
{
	if (n >= 10)
		ft_itoa_rec(n / 10, end - 1);
	*end = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;
	char	*p;

	len = ft_ndigits(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	p = res + len;
	if (n < 0)
	{
		*res = '-';
		ft_itoa_rec(-(long)n, p - 1);
	}
	else
		ft_itoa_rec((long)n, p - 1);
	*p = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 0;
	printf("#%zu: %d\n", ft_ndigits(i), i);
	i = INT_MIN;
	printf("#%zu: %d\n", ft_ndigits(i), i);
	i = INT_MAX;
	printf("#%zu: %d\n", ft_ndigits(i), i);
	i = 12345;
	printf("#%zu: %d\n", ft_ndigits(i), i);
	i = -12345;
	printf("#%zu: %d\n", ft_ndigits(i), i);
	i = 5;
	printf("#%zu: %d\n", ft_ndigits(i), i);
}
*/
