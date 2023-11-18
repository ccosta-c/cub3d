/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:30:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/15 11:40:10 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(int fd, char *buffer, char *stash)
{
    int		bytes_read;
    char	*temp;

    bytes_read = 1;
    while (bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return (0);
        if (bytes_read == 0)
            break ;
        buffer[bytes_read] = '\0';
        if (!stash)
            stash = ft_strdup("");
        temp = stash;
        stash = ft_strjoin(temp, buffer);
        free(temp);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    return (stash);
}

static char	*ft_get_stash(char *line)
{
    int		i;
    char	*stash;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (line[i] == '\0')
        return (0);
    stash = ft_substr(line, i + 1, ft_strlen(line) - i);
    if (stash[0] == '\0')
    {
        free(stash);
        stash = 0;
    }
    line[i + 1] = '\0';
    return (stash);
}

char	*get_next_line(int fd)
{
    char		*buffer;
    char		*line;
    static char	*stash[FOPEN_MAX];

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
        return (0);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (0);
    line = ft_get_line(fd, buffer, stash[fd]);
    free(buffer);
    if (!line)
    {
        free(stash[fd]);
        stash[fd] = 0;
        return (stash[fd]);
    }
    stash[fd] = ft_get_stash(line);
    return (line);
}