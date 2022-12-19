/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:43:57 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/19 15:43:48 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "common_utils.h" 
#include "map_utils.h"
#include "libft.h"
#include <math.h>

void	angle(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
			*ang = 360 + *ang;
	if (*ang >= 360)
			*ang = *ang - 360;
}

int	ft_mouse_move(int x, int y, t_data *data)
{
	data->map->rots[Y] += (x - data->mlx->last_click.axes[X]);
	data->map->rots[X] += (data->mlx->last_click.axes[Y] - y);
	data->mlx->last_click.axes[X] = x;
	data->mlx->last_click.axes[Y] = y;
	ft_apply_and_draw(data->map, data->mlx);
}

int	ft_mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		data->map->scale *= 0.5;
		data->map->trans[X] *= 0.5;
		data->map->trans[Y] *= 0.5;
		data->map->trans[X] += (x - x * 0.5);
		data->map->trans[Y] += (y - y * 0.5);
	}
	else if (button == 5)
	{
		data->map->scale *= 2;
		data->map->trans[X] *= 2;
		data->map->trans[Y] *= 2;
		data->map->trans[X] += (x - x * 2);
		data->map->trans[Y] += (y - y * 2);
	}
	else if (button == 1)
	{
		ft_printf("x:%d, y:%d\n", x, y);
		data->mlx->last_click.axes[X] = x;
		data->mlx->last_click.axes[Y] = y;
		data->mlx->mouse_held = 1;
	}
	if (button == 4 || button == 5)
		ft_apply_and_draw(data->map, data->mlx);
}
