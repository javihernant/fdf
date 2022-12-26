/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:35:17 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/22 18:11:24 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_utils.h"

void	ft_print_point(t_point *p)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_printf("%d,", p->axes[i]);
		i++;
	}
	ft_printf("%d", p->color);
}

void	ft_print_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			ft_print_point(&map->pts[i * map->w + j]);
			ft_printf(" ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_print_map_data(t_map *map)
{
	printf("Width: %d\n", map->w);
	printf("Height: %d\n", map->h);
	printf("Scale: %f\n", map->scale);
	printf("Zdiv: %f\n", map->zdiv);
	printf("X Translation: %f\n", map->trans[X]);
	printf("Y Translation: %f\n", map->trans[Y]);
	printf("Z Translation: %f\n", map->trans[Z]);
	printf("X Rotation: %f\n", map->rots[X]);
	printf("Y Rotation: %f\n", map->rots[Y]);
	printf("Z Rotation: %f\n", map->rots[Z]);
}
