/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:25:15 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/04/29 14:18:58 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_internal.h"
#include "libft.h"

static int	ft_vasprintf(char **ret, const char *f, va_list *ap)
{
	va_list	ap2;
	size_t	len;

	va_copy(ap2, *ap);
	len = ft_walk(f, ap, NULL);
	*ret = malloc(len + 1);
	if (!*ret)
		return (va_end(ap2), -1);
	ft_walk(f, &ap2, *ret);
	va_end(ap2);
	(*ret)[len] = '\0';
	return (len);
}

int	ft_asprintf(char **ret, const char *f, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, f);
	len = ft_vasprintf(ret, f, &ap);
	va_end(ap);
	return (len);
}

static int	ft_vdprintf(int fd, const char *f, va_list *ap)
{
	char	*buf;
	int		len;
	int		ret;

	len = ft_vasprintf(&buf, f, ap);
	if (len < 0)
		return (-1);
	ret = write(fd, buf, len);
	return (free(buf), ret);
}

int	ft_dprintf(int fd, const char *f, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, f);
	ret = ft_vdprintf(fd, f, &ap);
	va_end(ap);
	return (ret);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, f);
	ret = ft_vdprintf(1, f, &ap);
	va_end(ap);
	return (ret);
}
