/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:28:09 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/28 21:24:04 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *s)
{
	unsigned int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	if (sign < 0 && res == (unsigned)INT_MIN)
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
	printf("val:%d\n", INT_MIN);
	printf("val:%u\n", (unsigned)INT_MIN);
	printf("val:%u\n", -(unsigned)INT_MIN);
}
*/
