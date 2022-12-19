/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:17:51 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/19 15:26:46 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_utils.h"
#include "map_utils.h"
#include <time.h>
#include <stdlib.h>

static void	ft_draw_pts(t_map *map, t_mlx_data *data)
{
	int	i;
	int	j;

	j = 0;
	ft_set_color(COL_BLCK, data);
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

void	ft_apply_and_draw(t_map *map, t_mlx_data *data)
{
	float	trans[3];
	clock_t	t;
	double	p;
	size_t	len;

	ft_print_map_data(map);
	ft_memcpy(map->pts, map->mat, sizeof(t_point) * map->w * map->h);
	ft_bend(map);
	ft_rotate(map);
	ft_mat_scale(map->pts, map->w * map->h, map->scale);
	ft_mat_trans(map->pts, map->w * map->h, map->trans);
	t = clock();
	ft_draw_pts(map, data);
	t = clock() - t;
	p = (double) t / CLOCKS_PER_SEC;
}
