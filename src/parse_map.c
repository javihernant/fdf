/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:52:35 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/24 18:05:44 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map_utils.h"
#include "common_utils.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static int	ft_get_mapdata(char *path, int *width, int *height)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (1);
	*width = ft_get_width(line);
	*height = 0;
	while (line != NULL)
	{
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	**ft_alloc_maps(int width, int height)
{
	int	**maps;

	if (width <= 0 || height <= 0)
		return (0);
	maps = malloc(sizeof(int *) * 2);
	if (!maps)
		return (0);
	maps[0] = malloc(sizeof(int) * width * height);
	if (!maps[0])
		return (0);
	maps[1] = malloc(sizeof(int) * width * height);
	if (!maps[1])
	{
		free(maps[0]);
		return (0);
	}
	return (maps);
}

static int	ft_store_line(char *line, int **maps, int row, int width)
{
	char	**values;
	char	*val;
	int		i;

	values = ft_split(line, ' ');
	if (!values)
		return (1);
	i = 0;
	while (values[i] != NULL)
	{
		val = values[i];
		maps[0][row * width + i] = ft_atoi(val);
		while (ft_isdigit(*val))
			val++;
		maps[1][row * width + i] = (int) ft_hex_atoi(val);
		free(values[i]);
		i++;
	}
	free(values);
	return (0);
}

static int	ft_fill_maps(int **maps, int width, char *path)
{
	int		fd;
	int		i;
	char	*line;
	int		rc;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	rc = 0;
	while (line != NULL)
	{
		rc = ft_store_line(line, maps, i, width);
		free(line);
		if (rc != 0)
			break ;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (rc);
}

int	**ft_parse_maps(char *path, int *width, int *height)
{
	int	**maps;

	if (ft_get_mapdata(path, width, height) != 0)
		return (0);
	maps = ft_alloc_maps(*width, *height);
	if (!maps)
		return (0);
	if (ft_fill_maps(maps, *width, path) != 0)
	{
		free(maps[0]);
		free(maps[1]);
		free(maps);
		return (0);
	}
	return (maps);
}
