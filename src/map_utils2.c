/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:20:46 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:22:16 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "map_utils.h"

void	ft_set_zdiv(t_map *map)
{
	float	rat;

	map->zdiv = 1;
	rat = (float) map->zmax / map->w;
	if (rat > 0.5)
		map->zdiv = rat * 20;
}

void	ft_reset_props(t_map *map)
{
	map->view = DFLT_VW;
	map->scale = 50;
	map->rots[X] = 0;
	map->rots[Y] = 0;
	map->rots[Z] = 0;
	ft_set_zdiv(map);
	ft_center(map->trans);
	map->brange = 0;
}

void	ft_free_map(t_map *map)
{
	free(map->pts);
	map->pts = NULL;
	free(map->mat);
	map->mat = NULL;
}

/* Check if all of the points coords are within the screen resolution */
static int	ft_all_points_in(t_map *map)
{
	int		i;
	t_point	*pt;

	ft_apply_props(map);
	i = 0;
	while (i < map->len)
	{
		pt = &map->pts[i];
		if (pt->axes[X] >= WIDTH - PADDING || pt->axes[X] < PANEL_W + PADDING)
			return (0);
		if (pt->axes[Y] >= HEIGHT - PADDING || pt->axes[Y] < PADDING)
			return (0);
		i++;
	}
	return (1);
}

void	ft_fit(t_map *map)
{
	ft_center(map->trans);
	map->scale = 1;
	while (ft_all_points_in(map))
	{
		map->scale += 2;
	}
	map->scale -= 2;
}
