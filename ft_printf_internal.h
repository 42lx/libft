/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 01:43:35 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/04/29 14:20:27 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define DECIMAL "0123456789"
# define HEXALOW "0123456789abcdef"
# define HEXAUPP "0123456789ABCDEF"
# define ULTOA_BUFSZ 21

char	*ft_ultoa(unsigned long n, const char *radix, char buf[ULTOA_BUFSZ]);
size_t	ft_emit(char *buf, size_t pos, const char *s, size_t len);
size_t	ft_fmt_spec(char c, va_list *ap, char *buf, size_t pos);
size_t	ft_walk(const char *f, va_list *ap, char *buf);
size_t	ft_fmt_char(char *buf, size_t pos, char c);
size_t	ft_fmt_str(char *buf, size_t pos, const char *s);
size_t	ft_fmt_uint(char *buf, size_t pos, unsigned int n, const char *radix);
size_t	ft_fmt_int(char *buf, size_t pos, int n);
size_t	ft_fmt_ptr(char *buf, size_t pos, const void *p);

#endif
