/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:31:59 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/30 13:55:09 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale_map(t_map *map, t_mlx_data *data)
{
	float	sx;
	float	sy;
	int		i;
	int		j;
	t_point	*pt;

	sx = (double) map->w / data->w;
	sy = (double) map->h / data->h;
	i = 0;
	j = 0;
	while (j < map->h)
	{
		i = 0;
		while (i < map->w)
		{
			pt = &map->pts[j * map->w + i];
			pt->x = pt->x / sx;
			pt->y = pt->y / sy;
			i++;
		}
		j++;
	}
}
