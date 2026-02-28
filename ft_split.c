/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:54:13 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/02/28 12:50:33 by ohaponiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (in_word)
				count++;
			in_word = 0;
		}
		else
			in_word = 1;
		i++;
	}
	if (in_word)
		count++;
	return (count);
}

void	*ft_free_array(void **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split_populate(const char *s, char c, char **res, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	j_beg;
	size_t	k;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (s[j] == c)
			j++;
		j_beg = j;
		while (s[j] && s[j] != c)
			j++;
		res[i] = malloc(j - j_beg + 2);
		if (!res[i])
			return (ft_free_array((void **)res));
		k = -1;
		while (j_beg + (++k) < j)
			res[i][k] = s[j_beg + k];
		res[i][k] = '\0';
		i++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	len;

	len = ft_count_words(s, c);
	res = ft_calloc(len + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (ft_split_populate(s, c, res, len));
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
	while (tab[i])
		printf("%s$\n", tab[i++]);
}
*/
