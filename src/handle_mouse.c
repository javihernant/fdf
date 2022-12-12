/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:43:57 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/12 19:32:57 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "common_utils.h" 
#include "map_utils.h"
#include "libft.h"

int	ft_mouse_move(int x, int y, t_data *data)
{
	t_point	*last_click;
	float	angles[2];

	ft_printf("x:%d, y:%d\n", x, y);
	last_click = &data->mlx->last_click;
	if (1 || (ft_abs(x - last_click->axes[X]) > MIN_DIST || ft_abs(y - last_click->axes[Y]) > MIN_DIST))
	{
		angles[Y] = (x - last_click->axes[X]);
		angles[X] = (last_click->axes[Y] - y);
		ft_rotate_x(data->map, angles[X]);
		ft_rotate_y(data->map, angles[Y]);
		ft_draw_map(data->map, data->mlx);
		last_click->axes[X] = x;
		last_click->axes[Y] = y;
	}
}

int	ft_mouse_release(int button, int x, int y, t_data *data)
{
	ft_printf("x:%d, y:%d\n", x, y);
	(void) button;
	(void) x;
	(void) y;
	data->mlx->mouse_held = 0;
}

int	ft_mouse_press(int button, int x, int y, t_data *data)
{
	t_point	cnt;

	cnt.axes[X] = x;
	cnt.axes[Y] = y;
	if (button == 4)
	{
		ft_scale_map(data->map, 0.5, &cnt);
	}
	else if (button == 5)
	{
		ft_scale_map(data->map, 2, &cnt);
	}
	else if (button == 1)
	{
		ft_printf("x:%d, y:%d\n", x, y);
		data->mlx->last_click.axes[X] = x;
		data->mlx->last_click.axes[Y] = y;
		data->mlx->mouse_held = 1;
	}
	ft_draw_map(data->map, data->mlx);
}
