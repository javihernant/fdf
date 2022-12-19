/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:16:57 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/19 14:23:07 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include "map_utils.h"
#include "matrix.h"
#include <stdio.h>

int	ft_get_width(char *line)
{
	char	**values;
	int		i;	

	if (line == NULL)
		return (-1);
	values = ft_split(line, ' ');
	if (!values)
		return (-1);
	i = 0;
	while (values[i] != NULL)
	{
		free(values[i]);
		i++;
	}
	free(values);
	return (i);
}

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
	printf("X Translation: %f\n", map->trans[X]);
	printf("Y Translation: %f\n", map->trans[Y]);
	printf("Z Translation: %f\n", map->trans[Z]);
	printf("X Rotation: %f\n", map->rots[X]);
	printf("Y Rotation: %f\n", map->rots[Y]);
	printf("Z Rotation: %f\n", map->rots[Z]);
}



void	ft_rotate(t_map *map)
{
	ft_rotate_x(map->pts, map->w * map->h, map->rots[X]);
	ft_rotate_y(map->pts, map->w * map->h, map->rots[Y]);
	ft_rotate_z(map->pts, map->w * map->h, map->rots[Z]);
}

void	ft_bend(t_map *map)
{
	int		i;
	float	tmp;

	i = 0;
	while (i < map->w * map->h)
	{
		tmp = map->pts[i].axes[X] * map->pts[i].axes[X] * map->brange +
			map->pts[i].axes[Y] * map->pts[i].axes[Y] * map->brange;
		map->pts[i].axes[Z] -= tmp;
		i++;
	}
}
