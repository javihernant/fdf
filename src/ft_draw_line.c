/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:59:35 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/09 11:22:22 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "common_utils.h"
#include "mlx_utils.h"
#include "draw_line.h"

void	ft_draw_line_low(t_point *a, t_point *b, t_mlx_data *data)
{
	float	dif[2];
	t_point	tmp;
	int		yi;
	int		d;

	ft_2pts_dif(dif, a, b);
	ft_calc_inc(&yi, &dif[Y]);
	d = (2 * dif[Y]) - dif[X];
	ft_copy_pt(&tmp, a);
	while (tmp.axes[X] <= b->axes[X])
	{
		ft_calc_color_low(&tmp, b->axes[X], a->color, b->color);
		ft_pixel_put(&tmp, data);
		if (d > 0)
		{
			tmp.axes[Y] += yi;
			d += (2 * (dif[Y] - dif[X]));
		}
		else
			d += 2 * dif[Y];
		tmp.axes[X]++;
	}
}

void	ft_draw_line_high(t_point *a, t_point *b, t_mlx_data *data)
{
	float	dif[2];
	t_point	tmp;
	int		xi;
	int		d;

	ft_2pts_dif(dif, a, b);
	ft_calc_inc(&xi, &dif[X]);
	d = (2 * dif[X]) - dif[Y];
	ft_copy_pt(&tmp, a);
	while (tmp.axes[Y] <= b->axes[Y])
	{
		ft_calc_color_high(&tmp, b->axes[Y] + 1, a->color, b->color);
		ft_pixel_put(&tmp, data);
		if (d > 0)
		{
			tmp.axes[X] += xi;
			d += (2 * (dif[X] - dif[Y]));
		}
		else
			d += 2 * dif[X];
		tmp.axes[Y]++;
	}
}

void	ft_draw_line(t_point *a, t_point *b, t_mlx_data *data)
{
	if (ft_abs(b->axes[Y] - a->axes[Y]) < ft_abs(b->axes[X] - a->axes[X]))
	{
		if (a->axes[X] < b->axes[X])
			ft_draw_line_low(a, b, data);
		else
			ft_draw_line_low(b, a, data);
	}
	else
	{
		if (a->axes[Y] < b->axes[Y])
			ft_draw_line_high(a, b, data);
		else
			ft_draw_line_high(b, a, data);
	}
}
