/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:52:35 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 18:41:30 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parse_utils.h"
#include <stdlib.h>

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

int	ft_parse_map(char *path, t_map *map)
{
	if (ft_check_format(path) != 0)
		return (1);
	if (ft_init_w_and_h(path, map) != 0)
		return (1);
	if (ft_alloc_map_mem(map) != 0)
		return (1);
	if (ft_fill_mat(map, path) != 0)
	{
		free(map->pts);
		map->pts = NULL;
		return (1);
	}
	ft_init_mapdata(map);
	return (0);
}
