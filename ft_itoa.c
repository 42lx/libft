/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:22:06 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/15 13:45:57 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 1 + (n < 0);
	n = ft_abs(n);
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_rec(int n, char *end)
{
	if (n >= 10)
		ft_itoa_rec(n / 10, end - 1);
	*end = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	char	*p;
	size_t	len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	p = res;
	if (n < 0)
		*p = '-';
	n = ft_abs(n);
	p += len;
	*p = '\0';
	ft_itoa_rec(n, p - 1);
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 0;
	printf("#%zu: %d\n", ft_intlen(i), i);
	i = INT_MIN;
	printf("#%zu: %d\n", ft_intlen(i), i);
	i = INT_MAX;
	printf("#%zu: %d\n", ft_intlen(i), i);
	i = 12345;
	printf("#%zu: %d\n", ft_intlen(i), i);
	i = -12345;
	printf("#%zu: %d\n", ft_intlen(i), i);
	i = 5;
	printf("#%zu: %d\n", ft_intlen(i), i);
}
*/
