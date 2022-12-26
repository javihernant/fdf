/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:31:42 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 18:42:14 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "common_utils.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	ft_store_point(char *pt_str, int i, int j, t_map *map)
{
	t_point	*pt;

	pt = &map->mat[i * map->w + j];
	pt->axes[X] = j;
	pt->axes[Y] = i;
	pt->axes[Z] = ft_atoi(pt_str);
	while (ft_isdigit(*pt_str))
		pt_str++;
	if (map->has_color == 0 && *pt_str == ',')
		map->has_color = 1;
	pt->color = ft_hex_atoi(pt_str);
}

static int	ft_store_line(t_map *map, char *line, int row)
{
	char	**pts;
	int		i;

	pts = ft_split(line, ' ');
	if (!pts)
		return (1);
	i = 0;
	while (pts[i] != NULL)
	{
		ft_store_point(pts[i], row, i, map);
		free(pts[i]);
		i++;
	}
	free(pts);
	return (0);
}

int	ft_fill_mat(t_map *map, char *path)
{
	int		fd;
	int		i;
	char	*line;
	int		rc;

	map->has_color = 0;
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

int	ft_init_w_and_h(char *path, t_map *map)
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
