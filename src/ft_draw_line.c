/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:59:35 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/28 19:54:29 by jahernan         ###   ########.fr       */
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
	int	p;
	int	alpha;
	int	red;
	int	green;
	int	blue;

	p = (curr->x * 100 / width);
	alpha = ft_get_alpha(col_a) + ((ft_get_alpha(col_b) - ft_get_alpha(col_a))
		* p) / 100;
	red = ft_get_red(col_a) + ((ft_get_red(col_b) - ft_get_red(col_a))
		* p) / 100;
	green = ft_get_green(col_a) + ((ft_get_green(col_b) - ft_get_green(col_a))
		* p) / 100;
	blue = ft_get_blue(col_a) + ((ft_get_blue(col_b) - ft_get_blue(col_a))
		* p) / 100;
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

	dif.x = b.x - a.x;
	dif.y = b.y - a.y;
	yi = 1;
	if (dif.y < 0)
	{
		yi = -1;
		dif.y = -dif.y;
	}
	d = (2 * dif.y) - dif.x;
	tmp.x = a.x;
	tmp.y = a.y;
	while (tmp.x <= b.x)
	{
		ft_calc_color_low(&tmp, dif.x + 1, a.color, b.color);
		ft_pixel_put(&tmp, data);
		//tmp.y += ft_inc(&d, &dif);
		if (d > 0)
		{
			tmp.y += yi;
			d += (2 * (dif.y - dif.x));
		}
		else
			d += 2 * dif.y;
		tmp.x++;
	}
}

void	ft_draw_line_high(t_point a, t_point b, t_mlx_data *data)
{
	t_point	dif;
	int		xi;
	int		d;

	dif.x = b.x - a.x;
	dif.y = b.y - b.y;
	xi = 1;
	if (dif.x < 0)
	{
		xi = -1;
		dif.x = -dif.x;
	}
	d = (2 * dif.x) - dif.y;
	while (a.y <= b.y)
	{
		ft_pixel_put(&a, data);
		if (d > 0)
		{
			a.x += xi;
			d += (2 * (dif.x - dif.y));
		}
		else
			d += 2 * dif.x;
		a.y++;
	}
}

void	ft_draw_line(t_point *a, t_point *b, t_mlx_data *data)
{
	if (ft_abs(b->y - a->y) < ft_abs(b->x - a->x))
	{
		if (a->x < b->x)
			ft_draw_line_low(*a, *b, data);
		else
			ft_draw_line_low(*b, *a, data);
	}
	else
	{
		if (a->y < b->y)
			ft_draw_line_high(*a, *b, data);
		else
			ft_draw_line_high(*b, *a, data);
	}
}
