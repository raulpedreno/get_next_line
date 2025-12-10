/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedreno <rpedreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:18:24 by rpedreno          #+#    #+#             */
/*   Updated: 2025/12/05 15:54:55 by rpedreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h> 
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_find_newline(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_extract_line(char *stash, int nl_pos);
char	*ft_extract_stash_rest(char *stash, int nl_pos);

#endif
