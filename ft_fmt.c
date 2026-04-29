/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 01:32:40 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/04/15 09:35:33 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_internal.h"

size_t	ft_fmt_char(char *buf, size_t pos, char c)
{
	return (ft_emit(buf, pos, &c, 1));
}

size_t	ft_fmt_str(char *buf, size_t pos, const char *s)
{
	if (!s)
		return (ft_emit(buf, pos, "(null)", 6));
	return (ft_emit(buf, pos, s, ft_strlen(s)));
}

size_t	ft_fmt_uint(char *buf, size_t pos, unsigned int n, const char *radix)
{
	char	tmp[ULTOA_BUFSZ];
	char	*res;

	res = ft_ultoa((unsigned long)n, radix, tmp);
	return (ft_emit(buf, pos, res, ft_strlen(res)));
}

size_t	ft_fmt_int(char *buf, size_t pos, int n)
{
	char	tmp[ULTOA_BUFSZ];
	char	*res;

	if (n < 0)
	{
		res = ft_ultoa(-(unsigned long)n, DECIMAL, tmp);
		*--res = '-';
	}
	else
		res = ft_ultoa((unsigned long)n, DECIMAL, tmp);
	return (ft_emit(buf, pos, res, ft_strlen(res)));
}

size_t	ft_fmt_ptr(char *buf, size_t pos, const void *p)
{
	char	tmp[ULTOA_BUFSZ];
	char	*res;

	if (!p)
		return (ft_emit(buf, pos, "(nil)", 5));
	res = ft_ultoa((unsigned long)p, HEXALOW, tmp);
	*--res = 'x';
	*--res = '0';
	return (ft_emit(buf, pos, res, ft_strlen(res)));
}
