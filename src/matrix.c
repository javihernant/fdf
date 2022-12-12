/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:04:47 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/10 20:30:11 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "fdf.h"
#include "map_utils.h"

void	ft_mx_mult(float mx[3][3], t_point *pt)
{
	int		i;
	int		j;
	float	tmp[3];

	ft_memset(tmp, 0, sizeof(float) * 3);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			tmp[i] += mx[i][j] * pt->axes[j];
			j++;
		}
		i++;
	}
	i = 0;
	ft_memcpy(pt->axes, tmp, sizeof(float) * 3);
}

t_point	ft_get_map_center(t_map *map)
{
	int		i;
	int		j;
	int		k;
	float	mins[3];
	t_point	pt;

	ft_memset(mins, 0, sizeof(float) * 3);
	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			k = 0;
			pt = map->pts[i * map->w + j];
			while (k < 3)
			{
				mins[k] += pt.axes[k];
				k++;
			}
			j++;
		}
		i++;
	}
	k = 0;
	while (k < 3)
	{
		mins[k] /= (map->h * map->w);
		pt.axes[k] = mins[k];
		k++;
	}
	return (pt);
}

void	ft_rotate_x(t_map *map, float angle)
{
	int		i;
	int		j;
	float	rad;
	float	mx[3][3];
	t_point	pt;
	t_point	vec;

	ft_memset(mx, 0, sizeof(float) * 3 * 3);
	rad = angle * M_PI / 180;
	mx[0][0] = 1;
	mx[1][1] = cosf(rad);
	mx[1][2] = -sinf(rad);
	mx[2][1] = sinf(rad);
	mx[2][2] = cosf(rad);
	pt = ft_get_map_center(map);
	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			ft_mx_mult(mx, &map->pts[i * map->w + j]);
			j++;
		}
		i++;
	}
	vec.axes[X] = pt.axes[X];
	vec.axes[Y] = pt.axes[Y];
	vec.axes[Z] = pt.axes[Z];
	ft_mx_mult(mx, &vec);
	vec.axes[X] = pt.axes[X] - vec.axes[X];
	vec.axes[Y] = pt.axes[Y] - vec.axes[Y];
	ft_translate_map(map, &vec);
}

void	ft_rotate_y(t_map *map, float angle)
{
	int		i;
	int		j;
	float	rad;
	float	mx[3][3];
	t_point	pt;
	t_point	vec;

	ft_memset(mx, 0, sizeof(float) * 3 * 3);
	rad = angle * M_PI / 180;
	mx[0][0] = cosf(rad);
	mx[0][2] = sinf(rad);
	mx[1][1] = 1;
	mx[2][0] = -sinf(rad);
	mx[2][2] = cosf(rad);
	pt = ft_get_map_center(map);
	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			ft_mx_mult(mx, &map->pts[i * map->w + j]);
			j++;
		}
		i++;
	}
	vec.axes[X] = pt.axes[X];
	vec.axes[Y] = pt.axes[Y];
	vec.axes[Z] = pt.axes[Z];
	ft_mx_mult(mx, &vec);
	vec.axes[X] = pt.axes[X] - vec.axes[X];
	vec.axes[Y] = pt.axes[Y] - vec.axes[Y];
	ft_translate_map(map, &vec);
}

void	ft_rotate_z(t_map *map, float angle)
{
	int		i;
	int		j;
	float	rad;
	float	mx[3][3];
	t_point	pt;
	t_point	vec;

	ft_memset(mx, 0, sizeof(float) * 3 * 3);
	rad = angle * M_PI / 180;
	mx[0][0] = cosf(rad);
	mx[0][1] = -sinf(rad);
	mx[1][0] = sinf(rad);
	mx[1][1] = cosf(rad);
	mx[2][2] = 1;
	pt = ft_get_map_center(map);
	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			ft_mx_mult(mx, &map->pts[i * map->w + j]);
			j++;
		}
		i++;
	}
	vec.axes[X] = pt.axes[X];
	vec.axes[Y] = pt.axes[Y];
	vec.axes[Z] = pt.axes[Z];
	ft_mx_mult(mx, &vec);
	vec.axes[X] = pt.axes[X] - vec.axes[X];
	vec.axes[Y] = pt.axes[Y] - vec.axes[Y];
	ft_translate_map(map, &vec);
}
