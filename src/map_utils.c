/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:16:57 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/21 11:05:40 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "map_utils.h"
#include "matrix.h"
#include <stdlib.h>

void	ft_rotate(t_map *map)
{
	ft_rotate_x(map->pts, map->w * map->h, map->rots[X]);
	ft_rotate_y(map->pts, map->w * map->h, map->rots[Y]);
	ft_rotate_z(map->pts, map->w * map->h, map->rots[Z]);
}

void	ft_bend(t_map *map)
{
	int		i;
	float	tmp;

	i = 0;
	while (i < map->len)
	{
		tmp = map->pts[i].axes[X] * map->pts[i].axes[X] * map->brange +
			map->pts[i].axes[Y] * map->pts[i].axes[Y] * map->brange;
		map->pts[i].axes[Z] -= tmp;
		i++;
	}
}

void	ft_zdiv(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->len)
	{
		map->pts[i].axes[Z] /= map->zdiv;
		i++;
	}
}

void	ft_reset_props(t_map *map)
{
	map->scale = 50;
	map->trans[X] = WIDTH / 2;
	map->trans[Y] = HEIGHT / 2;
	map->trans[Z] = 0;
	map->rots[X] = 0;
	map->rots[Y] = 0;
	map->rots[Z] = 0;
	map->brange = 0;
}

void	ft_free_map(t_map *map)
{
	free(map->pts);
	map->pts = NULL;
	free(map->mat);
	map->mat = NULL;
}
