/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:32:01 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/18 04:00:28 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putnbr_fd_rec(long ln, int fd)
{
	if (ln >= 10)
		ft_putnbr_fd_rec(ln / 10, fd);
	ft_putchar_fd(ln % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_rec(-(long)n, fd);
	}
	else
		ft_putnbr_fd_rec((long)n, fd);
}
