/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedreno <rpedreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:46:16 by rpedreno          #+#    #+#             */
/*   Updated: 2025/12/10 16:34:57 by rpedreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_update_stash(char *buf, char *stash, int bytesread)
{
	if (bytesread < 0)
		return (free(stash), NULL);
	if (bytesread == 0)
		return (stash);
	buf[bytesread] = '\0';
	stash = ft_strjoin_gnl(stash, buf);
	return (stash);
}

char	*ft_extract_line_update(char **stash)
{
	int		nlpos;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	nlpos = ft_find_newline(*stash);
	line = ft_extract_line(*stash, nlpos);
	*stash = ft_extract_stash_rest(*stash, nlpos);
	return (line);
}

char	*ft_return_rest(char **stash)
{
	char	*line;

	line = ft_extract_line(*stash, -1);
	free(*stash);
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	int			bytesread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0 && ft_find_newline(stash) < 0)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		stash = ft_update_stash(buf, stash, bytesread);
		if (!stash)
			return (free (buf), NULL);
	}
	free (buf);
	if (stash && ft_find_newline(stash) >= 0)
		return (ft_extract_line_update(&stash));
	if (stash && *stash != '\0')
		return (ft_return_rest(&stash));
	return (free(stash), stash = NULL, NULL);
}
/*
int main(void)
{
    int fd;
    char *line;

    fd = 0;
    fd = open("texto.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}*/
