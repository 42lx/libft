/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:28:09 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/24 12:44:05 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

int	ft_atoi(const char *s)
{
	size_t			i;
	unsigned int	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + (s[i] - '0');
		if (res > (unsigned)INT_MAX + (sign < 0))
			return (0);
		i++;
	}
	if (sign < 0 && res == -(unsigned)INT_MIN)
		return (INT_MIN);
	return (res * sign);
}

/*
#include <stdio.h>
int	main(void)
{
	// Try this with cc -ftrapv
	printf("res:%d\n", ft_atoi("-2147483648"));
	printf("res:%d\n", ft_atoi("-2147483647"));
	printf("res:%d\n", ft_atoi("2147483647"));
	printf("res:%d\n", ft_atoi("214748364999999999999999999999"));
	printf("res:%d\n", ft_atoi("0"));
}
*/
