/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:00:27 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/08 17:48:02 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_linelen(char *str)
{
	int	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;

	len = ft_linelen(s1) + ft_linelen(s2);
	str = (char *) malloc(len + 1);
	if (!str)
	{
		free(s1);
		free(s2);
		return (0);
	}
	i = ft_linecpy(str, s1);
	ft_linecpy(&str[i], s2);
	free(s1);
	free(s2);
	return (str);
}

static void	ft_line_shift(char *buffer, int idx)
{
	int	i;

	i = 0;
	while (idx < BUFFER_SIZE + 1)
	{
		buffer[i] = buffer[idx];
		i++;
		idx++;
	}
}

/* takes current allocated line and expands it with the data in buffer. When it
 * finds a newline in buffer, it shifts everything after the newline to the
 * begining of the array. If it finds a newline, that means a line has been
 * found, so program has to stop. For that we equals the rc to 0 */
char	*ft_expand_line(char *line, char *buffer, int *rc)
{
	char	*tmp;
	int		copied;

	if (*buffer == '\0')
		return (0);
	tmp = malloc(ft_linelen(buffer) + 1);
	if (!tmp)
	{
		*rc = 0;
		free(line);
		return (0);
	}
	copied = ft_linecpy(tmp, buffer);
	line = ft_strjoin(line, tmp);
	if (!line)
		*rc = 0;
	if (*rc != 0 && ft_find_nl(buffer) != -1)
		*rc = 0;
	ft_line_shift(buffer, copied);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffers[MAX_FD][BUFFER_SIZE + 1];
	int				rc;
	char			*line;

	if (fd >= MAX_FD || fd < 0)
		return (0);
	rc = 1;
	line = 0;
	line = ft_expand_line(line, buffers[fd], &rc);
	while (rc != 0)
	{
		rc = read(fd, buffers[fd], BUFFER_SIZE);
		if (rc == 0 || rc == -1)
			break ;
		buffers[fd][rc] = '\0';
		line = ft_expand_line(line, buffers[fd], &rc);
	}
	return (line);
}
