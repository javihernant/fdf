/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:16:02 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/09 11:18:57 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_utils.h"

void	ft_copy_pt(t_point *tmp, t_point *a)
{
	tmp->axes[X] = a->axes[X];
	tmp->axes[Y] = a->axes[Y];
	tmp->color = a->color;
}

void	ft_calc_inc(int *inc, float *dif)
{
	*inc = 1;
	if (*dif < 0)
	{
		*inc = -1;
		*dif = -*dif;
	}
}

void	ft_2pts_dif(float dif[2], t_point *a, t_point *b)
{
	dif[X] = b->axes[X] - a->axes[X];
	dif[Y] = b->axes[Y] - a->axes[Y];
}

void	ft_calc_color_low(t_point *curr, int width, int col_a, int col_b)
{
	float	p;
	int		alpha;
	int		red;
	int		green;
	int		blue;

	p = (curr->axes[X] / width);
	alpha = ft_get_alpha(col_a) + p * ((float)(ft_get_alpha(col_b) \
			- ft_get_alpha(col_a)));
	red = ft_get_red(col_a) + p * ((float)(ft_get_red(col_b) \
			- ft_get_red(col_a)));
	green = ft_get_green(col_a) + p * ((float)(ft_get_green(col_b) \
			- ft_get_green(col_a)));
	blue = ft_get_blue(col_a) + p * ((float)(ft_get_blue(col_b) \
			- ft_get_blue(col_a)));
	curr->color = ((alpha & 0xff) << 24
			| (red & 0xff) << 16
			| (green & 0xff) << 8
			| (blue & 0xff));
}

void	ft_calc_color_high(t_point *curr, int width, int col_a, int col_b)
{
	float	p;
	int		alpha;
	int		red;
	int		green;
	int		blue;

	p = (curr->axes[Y] / width);
	alpha = ft_get_alpha(col_a) + p * ((float)(ft_get_alpha(col_b) \
			- ft_get_alpha(col_a)));
	red = ft_get_red(col_a) + p * ((float)(ft_get_red(col_b) \
			- ft_get_red(col_a)));
	green = ft_get_green(col_a) + p * ((float)(ft_get_green(col_b) \
			- ft_get_green(col_a)));
	blue = ft_get_blue(col_a) + p * ((float)(ft_get_blue(col_b) \
			- ft_get_blue(col_a)));
	curr->color = ((alpha & 0xff) << 24
			| (red & 0xff) << 16
			| (green & 0xff) << 8
			| (blue & 0xff));
}
