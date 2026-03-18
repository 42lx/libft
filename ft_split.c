/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:54:13 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/03/18 03:24:22 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

static void	*ft_free_array(void **arr)
{
	void	**p;

	p = arr;
	while (*p)
		free(*p++);
	free(arr);
	return (NULL);
}

static char	**ft_split_populate(char **res, const char *s, char c)
{
	const char	*start;
	char		**p;

	p = res;
	while (1)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s && *s != c)
			s++;
		*p = ft_substr(start, 0, s - start);
		if (!*p)
			return (ft_free_array((void **)res));
		p++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	res = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (ft_split_populate(res, s, c));
}

/*
#include <stdio.h>

int	main(void)
{
	char	*splitme;
	char	**tab;
	int		i;

	splitme = "--1-2--3---4----5-----42";
	tab = ft_split(splitme, '-');
	i = 0;
	while (*tab)
		printf("%s$\n", *tab++);
}
*/
