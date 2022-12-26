/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:59:35 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/26 23:19:47 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "common_utils.h"
#include "mlx_utils.h"

/*
static void	ft_init_draw_line(t_point *dif, int *inc, int *color_inc, int *d)
{
}
*/

static void	ft_calc_color_low(t_point *curr, int width, int col_a, int col_b)
{
	float	p;
	int	alpha;
	int	red;
	int	green;
	int	blue;

	p = (curr->axes[X] / width);
	alpha = ft_get_alpha(col_a) + ((float)(ft_get_alpha(col_b) - ft_get_alpha(col_a))
		* p);
	red = ft_get_red(col_a) + ((float)(ft_get_red(col_b) - ft_get_red(col_a))
		* p);
	green = ft_get_green(col_a) + ((float)(ft_get_green(col_b) - ft_get_green(col_a))
		* p);
	blue = ft_get_blue(col_a) + ((float)(ft_get_blue(col_b) - ft_get_blue(col_a))
		* p);
	curr->color = ((alpha & 0xff) << 24
			| (red & 0xff) << 16
			| (green & 0xff) << 8
			| (blue & 0xff));
}

static void	ft_calc_color_high(t_point *curr, int width, int col_a, int col_b)
{
	float	p;
	int	alpha;
	int	red;
	int	green;
	int	blue;

	p = (curr->axes[Y] / width);
	alpha = ft_get_alpha(col_a) + ((float)(ft_get_alpha(col_b) - ft_get_alpha(col_a))
		* p);
	red = ft_get_red(col_a) + ((float)(ft_get_red(col_b) - ft_get_red(col_a))
		* p);
	green = ft_get_green(col_a) + ((float)(ft_get_green(col_b) - ft_get_green(col_a))
		* p);
	blue = ft_get_blue(col_a) + ((float)(ft_get_blue(col_b) - ft_get_blue(col_a))
		* p);
	curr->color = ((alpha & 0xff) << 24
			| (red & 0xff) << 16
			| (green & 0xff) << 8
			| (blue & 0xff));
}

void	ft_draw_line_low(t_point a, t_point b, t_mlx_data *data)
{
	t_point	dif;
	t_point	tmp;
	int		yi;
	int		d;

	dif.axes[X] = b.axes[X] - a.axes[X];
	dif.axes[Y] = b.axes[Y] - a.axes[Y];
	yi = 1;
	if (dif.axes[Y] < 0)
	{
		yi = -1;
		dif.axes[Y] = -dif.axes[Y];
	}
	d = (2 * dif.axes[Y]) - dif.axes[X];
	tmp.axes[X] = a.axes[X];
	tmp.axes[Y] = a.axes[Y];
	while (tmp.axes[X] <= b.axes[X])
	{
		ft_calc_color_low(&tmp, b.axes[X], a.color, b.color);
		ft_pixel_put(&tmp, data);
		//tmp.y += ft_inc(&d, &dif);
		if (d > 0)
		{
			tmp.axes[Y] += yi;
			d += (2 * (dif.axes[Y] - dif.axes[X]));
		}
		else
			d += 2 * dif.axes[Y];
		tmp.axes[X]++;
	}
}

void	ft_draw_line_high(t_point a, t_point b, t_mlx_data *data)
{
	t_point	dif;
	t_point	tmp;
	int		xi;
	int		d;

	dif.axes[X] = b.axes[X] - a.axes[X];
	dif.axes[Y] = b.axes[Y] - a.axes[Y];
	xi = 1;
	if (dif.axes[X] < 0)
	{
		xi = -1;
		dif.axes[X] = -dif.axes[X];
	}
	d = (2 * dif.axes[X]) - dif.axes[Y];
	tmp.axes[X] = a.axes[X];
	tmp.axes[Y] = a.axes[Y];
	while (tmp.axes[Y] <= b.axes[Y])
	{
		ft_calc_color_high(&tmp, b.axes[Y] + 1, a.color, b.color);
		ft_pixel_put(&tmp, data);
		//tmp.y += ft_inc(&d, &dif);
		if (d > 0)
		{
			tmp.axes[X] += xi;
			d += (2 * (dif.axes[X] - dif.axes[Y]));
		}
		else
			d += 2 * dif.axes[X];
		tmp.axes[Y]++;
	}
}

void	ft_draw_line(t_point *a, t_point *b, t_mlx_data *data)
{
	if (ft_abs(b->axes[Y] - a->axes[Y]) < ft_abs(b->axes[X] - a->axes[X]))
	{
		if (a->axes[X] < b->axes[X])
			ft_draw_line_low(*a, *b, data);
		else
			ft_draw_line_low(*b, *a, data);
	}
	else
	{
		if (a->axes[Y] < b->axes[Y])
			ft_draw_line_high(*a, *b, data);
		else
			ft_draw_line_high(*b, *a, data);
	}
}
