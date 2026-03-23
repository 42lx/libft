/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:32:01 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/23 10:13:48 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putnbr_fd_rec(unsigned long n, int fd)
{
	if (n >= 10)
		ft_putnbr_fd_rec(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_rec(-(unsigned long)n, fd);
	}
	else
		ft_putnbr_fd_rec((unsigned long)n, fd);
}
