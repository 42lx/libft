/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:07:04 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/04/15 09:42:40 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_internal.h"

char	*ft_ultoa(unsigned long n, const char *radix, char buf[ULTOA_BUFSZ])
{
	size_t	rlen;
	char	*end;

	rlen = ft_strlen(radix);
	end = buf + ULTOA_BUFSZ - 1;
	*end = '\0';
	if (n == 0)
		*--end = radix[0];
	while (n)
	{
		*--end = radix[n % rlen];
		n /= rlen;
	}
	return (end);
}

size_t	ft_emit(char *buf, size_t pos, const char *s, size_t len)
{
	if (buf)
		ft_memcpy(buf + pos, s, len);
	return (pos + len);
}

size_t	ft_fmt_spec(char c, va_list *ap, char *buf, size_t pos)
{
	if (c == 'c')
		return (ft_fmt_char(buf, pos, (char)va_arg(*ap, int)));
	if (c == 's')
		return (ft_fmt_str(buf, pos, va_arg(*ap, char *)));
	if (c == 'u')
		return (ft_fmt_uint(buf, pos, va_arg(*ap, unsigned int), DECIMAL));
	if (c == 'x')
		return (ft_fmt_uint(buf, pos, va_arg(*ap, unsigned int), HEXALOW));
	if (c == 'X')
		return (ft_fmt_uint(buf, pos, va_arg(*ap, unsigned int), HEXAUPP));
	if (c == 'd' || c == 'i')
		return (ft_fmt_int(buf, pos, va_arg(*ap, int)));
	if (c == 'p')
		return (ft_fmt_ptr(buf, pos, va_arg(*ap, void *)));
	if (c == '%')
		return (ft_fmt_char(buf, pos, '%'));
	return (pos);
}

size_t	ft_walk(const char *f, va_list *ap, char *buf)
{
	size_t	pos;
	char	*next;

	pos = 0;
	while (1)
	{
		next = ft_strchr(f, '%');
		if (!next)
			return (ft_emit(buf, pos, f, ft_strlen(f)));
		pos = ft_emit(buf, pos, f, next - f);
		if (!next[1])
			return (pos);
		f = next + 1;
		pos = ft_fmt_spec(*f++, ap, buf, pos);
	}
}
