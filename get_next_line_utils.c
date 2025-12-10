/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedreno <rpedreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:17:58 by rpedreno          #+#    #+#             */
/*   Updated: 2025/12/10 12:07:45 by rpedreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	i = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (dest > src)
	{
		while (len--)
			temp_dest[len] = temp_src[len];
	}
	else
	{
		while (i < len)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (temp_dest);
}

int	ft_find_newline(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = malloc((s1len + s2len) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	ft_memmove(result, s1, s1len);
	ft_memmove(&result[s1len], s2, s2len);
	result[s1len + s2len] = '\0';
	free (s1);
	return (result);
}

char	*ft_extract_line(char *stash, int nl_pos)
{
	char	*line;
	size_t	len;
	size_t	i;

	if (!stash)
		return (NULL);
	if (nl_pos < 0)
		len = ft_strlen(stash);
	else
		len = (size_t)nl_pos + 1;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_extract_stash_rest(char *stash, int nl_pos)
{
	char	*new_stash;
	int		len;
	int		i;

	if (!stash || nl_pos < 0)
		return (NULL);
	len = 0;
	while (stash[nl_pos + len + 1])
		len++;
	if (len == 0)
		return (free (stash), NULL);
	new_stash = malloc(sizeof(char) * (len + 1));
	if (!new_stash)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_stash[i] = stash[nl_pos + 1 + i];
		i++;
	}
	new_stash[i] = '\0';
	return (free (stash), new_stash);
}
