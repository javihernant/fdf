/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:15:31 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/01 17:22:31 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	ft_isometric(t_map *map)
{
	int		i;
	int		j;
	t_point	*pt;

	j = 0;
	while (j < map->h)
	{
		i = 0;
		while (i < map->w)
		{
			pt = &map->pts[j * map->w + i];
			pt->y = (pt->x+2*pt->y+pt->z)/sqrt(6);
			pt->x = (pt->x - pt->z) / sqrt(2);
			i++;
		}
		j++;
	}
}
