/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:22:06 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/01 12:54:30 by ohaponiu         ###   ########.fr       */
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
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_rec(int n, char *end)
{
	if (n > 9)
		ft_itoa_rec(n / 10, end - 1);
	*end = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (n < 0)
		*res = '-';
	n = ft_abs(n);
	ft_itoa_rec(n, res + len - 1);
	*(res + len) = '\0';
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
