/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaponiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 18:24:07 by ohaponiu          #+#    #+#             */
/*   Updated: 2026/04/29 19:29:06 by mleitao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*read_to_cache(int fd, char *cache)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	buf[0] = '\0';
	bytes_read = 1;
	while (!ft_strchr(buf, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(cache), NULL);
		buf[bytes_read] = '\0';
		cache = ft_strjoin(cache, buf);
		if (!cache)
			return (NULL);
	}
	return (cache);
}

static char	*extract_line(char *cache, char *end)
{
	if (!cache[0])
		return (NULL);
	if (end)
		return (ft_substr(cache, end - cache + 1));
	else
		return (ft_substr(cache, ft_strlen(cache)));
}

static char	*trim_cache(char *cache, char *end)
{
	if (!end)
		return (free(cache), NULL);
	end++;
	ft_memcpy(cache, end, ft_strlen(end) + 1);
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;
	char		*end;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 1000000)
		return (NULL);
	cache = read_to_cache(fd, cache);
	if (!cache)
		return (NULL);
	end = ft_strchr(cache, '\n');
	line = extract_line(cache, end);
	cache = trim_cache(cache, end);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
