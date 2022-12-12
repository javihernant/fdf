/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:39 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/12 18:43:15 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"
#include "map_utils.h"
#include "libft.h"
#include "mlx_utils.h"

#define ANGLE 10
int	ft_handle_key(int keycode, t_data *data)
{
	t_point	vec;
	t_point	prev_cntr;

	prev_cntr.axes[X] = WIDTH / 2;
	prev_cntr.axes[Y] = HEIGHT / 2;
	if (keycode == XK_plus)
	{
		ft_scale_map(data->map, 2, &prev_cntr);
	}
	else if (keycode == XK_minus)
	{
		ft_scale_map(data->map, 0.5, &prev_cntr);
	}
	else if (keycode == XK_Left)
	{
		vec.axes[X] = -TRNSLT_RATE * data->map->scale;
		vec.axes[Y] = 0;
		ft_translate_map(data->map, &vec);
	}
	else if (keycode == XK_Right)
	{
		vec.axes[X] = TRNSLT_RATE * data->map->scale;
		vec.axes[Y] = 0;
		ft_translate_map(data->map, &vec);
	}
	else if (keycode == XK_Down)
	{
		vec.axes[X] = 0;
		vec.axes[Y] = TRNSLT_RATE * data->map->scale;
		ft_translate_map(data->map, &vec);
	}
	else if (keycode == XK_Up)
	{
		vec.axes[X] = 0;
		vec.axes[Y] = -TRNSLT_RATE * data->map->scale;
		ft_translate_map(data->map, &vec);
	}
	else if (keycode == XK_d)
	{
		ft_rotate_y(data->map, ANGLE);
	}
	else if (keycode == XK_a)
	{
		ft_rotate_y(data->map, -ANGLE);
	}
	else if (keycode == XK_w)
	{
		ft_rotate_x(data->map, ANGLE);
	}
	else if (keycode == XK_s)
	{
		ft_rotate_x(data->map, -ANGLE);
	}
	else if (keycode == XK_z)
	{
		ft_rotate_z(data->map, -ANGLE);
	}
	else if (keycode == XK_x)
	{
		ft_rotate_z(data->map, ANGLE);
	}
	ft_draw_map(data->map, data->mlx);
	return (0);
}
