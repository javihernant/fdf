/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:23:52 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:25:30 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h> 

static void	ft_trnsf_to_sph(t_map *map)
{
	int		i;
	t_point	*pt;
	float	map_rad;

	map_rad = map->w / (2 * M_PI);
	i = 0;
	while (i < map->len)
	{
		pt = &map->pts[i];
		pt->axes[X] = (pt->axes[Z] + map_rad) * cosf(pt->sph[PHI])
			* sinf(pt->sph[THETA]);
		pt->axes[Y] = (pt->axes[Z] + map_rad) * sinf(pt->sph[PHI])
			* sinf(pt->sph[THETA]);
		pt->axes[Z] = (pt->axes[Z] + map_rad) * cosf(pt->sph[THETA]);
		i++;
	}
}

static void	ft_set_sph_crds(t_map *map)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->len)
	{
		pt = &map->pts[i];
		pt->sph[THETA] = (pt->axes[Y] + map->h / 2) * (M_PI / (map->h - 1));
		pt->sph[PHI] = pt->axes[X] * (2 * M_PI / (map->w - 1));
		i++;
	}
}

void	ft_spherize(t_map *map)
{
	ft_set_sph_crds(map);
	ft_trnsf_to_sph(map);
}
