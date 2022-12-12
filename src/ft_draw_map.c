/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:17:51 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/06 14:04:49 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_utils.h"

void	ft_draw_map(t_map *map, t_mlx_data *data)
{
	int		i;
	int		j;

	ft_set_color(COL_BLCK, data);
	j = 0;
	while (j < map->h)
	{
		i = 0;
		while (i < map->w)
		{
			if (i + 1 < map->w)
			{
				ft_draw_line(&map->pts[j * map->w + i],
					&map->pts[j * map->w + i + 1], data);
			}
			if (j + 1 < map->h)
			{
				ft_draw_line(&map->pts[j * map->w + i],
					&map->pts[(j + 1) * map->w + i], data);
			}
			i++;
		}
		j++;
	}
	ft_update_img(data);
}
