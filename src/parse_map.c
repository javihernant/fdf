/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:52:35 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/20 01:41:40 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "map_utils.h"
#include "common_utils.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "matrix.h"

static int	ft_get_width(char *line)
{
	char	**values;
	int		i;	

	if (line == NULL)
		return (-1);
	values = ft_split(line, ' ');
	if (!values)
		return (-1);
	i = 0;
	while (values[i] != NULL)
	{
		free(values[i]);
		i++;
	}
	free(values);
	return (i);
}

static int	ft_init_w_and_h(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (1);
	map->w = ft_get_width(line);
	map->h = 0;
	while (line != NULL)
	{
		map->h++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->len = map->w * map->h;
	return (0);
}

static int	ft_init_mapdata(char *path, t_map *map)
{
	if (ft_init_w_and_h(path, map) != 0)
		return (1);
	if (ft_reset_props(map) != 0)
		return (1);
	return (0);
}

static int	ft_alloc_map_mem(t_map *map)
{
	if (map->w <= 0 || map->h <= 0)
		return (1);
	map->mat = malloc(sizeof(t_point) * map->w * map->h);
	if (!map->mat)
		return (1);
	map->pts = malloc(sizeof(t_point) * map->w * map->h);
	if (!map->pts)
		return (1);
	return (0);
}

static int	ft_store_line(t_map *map, char *line, int row)
{
	char	**values;
	char	*val;
	int		i;
	t_point	*pt;

	values = ft_split(line, ' ');
	if (!values)
		return (1);
	i = 0;
	while (values[i] != NULL)
	{
		val = values[i];
		pt = &map->mat[row * map->w + i];
		pt->axes[X] = i;
		pt->axes[Y] = row;
		pt->axes[Z] = ft_atoi(val);
		while (ft_isdigit(*val))
			val++;
		pt->color = ft_hex_atoi(val);
		free(values[i]);
		i++;
	}
	free(values);
	return (0);
}

static int	ft_fill_mat(t_map *map, char *path)
{
	int		fd;
	int		i;
	char	*line;
	int		rc;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	i = 0;
	rc = 0;
	while (line != NULL)
	{
		rc = ft_store_line(map, line, i);
		free(line);
		if (rc != 0)
			break ;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (rc);
}

void	ft_mat_to_orig(t_map *map)
{
	float	vec[3];

	vec[X] = -map->w / 2;
	vec[Y] = -map->h / 2;
	vec[Z] = -ft_midz(map) / 2;
	ft_mat_trans(map->mat, map->w * map->h, vec);
}

int	ft_parse_map(char *path, t_map *map)
{
	if (ft_init_mapdata(path, map) != 0)
		return (1);
	if (ft_alloc_map_mem(map) != 0)
		return (1);
	if (ft_fill_mat(map, path) != 0)
	{
		free(map->pts);
		map->pts = NULL;
		return (1);
	}
	ft_mat_to_orig(map);
	return (0);
}
