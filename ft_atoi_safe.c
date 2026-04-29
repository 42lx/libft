/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:28:45 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/04/29 03:33:17 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi_safe(const char *s, int *out)
{
	long	acc;
	int		sign;

	acc = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	if (!*s)
		return (-1);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (-1);
		acc = acc * 10 + (*s++ - '0');
		if (sign * acc < INT_MIN || sign * acc > INT_MAX)
			return (-1);
	}
	*out = (int)(sign * acc);
	return (0);
}
