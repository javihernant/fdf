/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:38 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:23:06 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "map_utils.h"
#include "matrix.h"
#include <stdlib.h>
#include "common_utils.h"
#include <math.h>

void	ft_rotate(t_map *map)
{
	ft_rotate_x(map->pts, map->len, map->rots[X]);
	ft_rotate_y(map->pts, map->len, map->rots[Y]);
	ft_rotate_z(map->pts, map->len, map->rots[Z]);
}

void	ft_bend(t_map *map)
{
	int		i;
	float	tmp;

	i = 0;
	while (i < map->len)
	{
		tmp = map->pts[i].axes[X] * map->pts[i].axes[X] * map->brange
			+ map->pts[i].axes[Y] * map->pts[i].axes[Y] * map->brange;
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

void	ft_zmult(t_point *mat, int len, int sc)
{
	int		i;

	i = 0;
	while (i < len)
	{
		mat[i].axes[Z] *= sc;
		i++;
	}
}

void	ft_center(float *trans)
{
	trans[X] = (WIDTH - PANEL_W) / 2 + PANEL_W + PADDING;
	trans[Y] = HEIGHT / 2 + PADDING;
	trans[Z] = 0;
}
