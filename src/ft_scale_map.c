/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:31:59 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/06 14:28:29 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map_utils.h"

void	ft_scale_map(t_map *map, float scale, t_point *prev_cntr)
{
	int		i;
	int		j;
	int		k;
	t_point	*pt;
	t_point	vec;

	j = 0;
	map->scale *= scale;
	while (j < map->h)
	{
		i = 0;
		while (i < map->w)
		{
			pt = &map->pts[j * map->w + i];
			k = 0;
			while (k < 3)
			{
				pt->axes[k] *= scale;
				k++;
			}
			i++;
		}
		j++;
	}
	vec.axes[X] = prev_cntr->axes[X] - prev_cntr->axes[X] * scale;
	vec.axes[Y] = prev_cntr->axes[Y] - prev_cntr->axes[Y] * scale;
	ft_translate_map(map, &vec);
}
