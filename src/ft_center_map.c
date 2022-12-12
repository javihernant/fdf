/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_center_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:56:43 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/06 13:46:02 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map_utils.h"

/* Center map using geometry translations. */
void	ft_center_map(t_map *map)
{
	t_point	vec;
	int		mid_idx;

	mid_idx = ((int) map->h / 2) * map->w + (int) map->w / 2;
	vec.axes[X] = WIDTH / 2 - map->pts[mid_idx].axes[X];
	vec.axes[Y] = HEIGHT / 2 - map->pts[mid_idx].axes[Y];
	ft_translate_map(map, &vec);
}
