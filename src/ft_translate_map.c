/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:57:59 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/05 18:32:01 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate_map(t_map *map, t_point *vec)
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
			pt->axes[X] += vec->axes[X];
			pt->axes[Y] += vec->axes[Y];
			i++;
		}
		j++;
	}
}
