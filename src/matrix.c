/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:04:47 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/19 16:39:54 by jahernan         ###   ########.fr       */
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

t_point	ft_central_pt(t_map *map, size_t len)
{
	size_t	i;
	size_t	k;
	float	tot[3];
	t_point	pt;

	ft_memset(tot, 0, sizeof(float) * 3);
	i = 0;
	while (i < len)
	{
		pt = map->pts[i];
		k = 0;
		while (k < 3)
		{
			tot[k] += pt.axes[k];
			k++;
		}
		i++;
	}
	k = 0;
	while (k < 3)
	{
		tot[k] /= (len);
		pt.axes[k] = tot[k];
		k++;
	}
	return (pt);
}

void	ft_rotate_x(t_point *mat, size_t len, float angle)
{
	size_t		i;
	float	mx[3][3];

	angle = angle * M_PI / 180;
	ft_memset(mx, 0, sizeof(float) * 3 * 3);
	mx[0][0] = 1;
	mx[1][1] = cosf(angle);
	mx[1][2] = -sinf(angle);
	mx[2][1] = sinf(angle);
	mx[2][2] = cosf(angle);
	i = 0;
	while (i < len)
	{
		ft_mx_mult(mx, &mat[i]);
		i++;
	}
}

void	ft_rotate_y(t_point *mat, size_t len, float angle)
{
	size_t		i;
	float	mx[3][3];

	angle = angle * M_PI / 180;
	ft_memset(mx, 0, sizeof(float) * 3 * 3);
	mx[0][0] = cosf(angle);
	mx[0][2] = sinf(angle);
	mx[1][1] = 1;
	mx[2][0] = -sinf(angle);
	mx[2][2] = cosf(angle);
	i = 0;
	while (i < len)
	{
		ft_mx_mult(mx, &mat[i]);
		i++;
	}
}

void	ft_rotate_z(t_point *mat, size_t len, float angle)
{
	size_t		i;
	float	mx[3][3];
	angle = angle * M_PI / 180;
	ft_memset(mx, 0, sizeof(float) * 3 * 3);
	mx[0][0] = cosf(angle);
	mx[0][1] = -sinf(angle);
	mx[1][0] = sinf(angle);
	mx[1][1] = cosf(angle);
	mx[2][2] = 1;
	i = 0;
	while (i < len)
	{
		ft_mx_mult(mx, &mat[i]);
		i++;
	}
}

void	ft_mat_scale(t_point *pts, size_t len, float scale)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (i < len)
	{
		k = 0;
		while (k < 3)
		{
			pts[i].axes[k] *= scale;
			k++;
		}
		i++;
	}
}

void	ft_mat_trans(t_point *pts, size_t len, float vec[3])
{
	size_t	i;
	size_t	k;

	i = 0;
	while (i < len)
	{
		k = 0;
		while (k < 3)
		{
			pts[i].axes[k] += vec[k];
			k++;
		}
		i++;
	}
}
