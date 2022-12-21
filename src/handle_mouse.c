/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:43:57 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/20 18:20:18 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "common_utils.h" 
#include "map_utils.h"
#include "libft.h"
#include <math.h>
#include "keycodes.h"
void	angle(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
			*ang = 360 + *ang;
	if (*ang >= 360)
			*ang = *ang - 360;
}

void	ft_mouse_rots(int x, int y, t_data *data)
{
	if (data->mlx->button == MOUSE_L)
	{
		data->map->rots[Y] += (x - data->mlx->last_click.axes[X]);
		data->map->rots[X] += (data->mlx->last_click.axes[Y] - y);
		data->mlx->last_click.axes[X] = x;
		data->mlx->last_click.axes[Y] = y;
		ft_apply_and_draw(data->map, data->mlx);
	}
}

void	ft_mouse_trans(int x, int y, t_data *data)
{
	if (data->mlx->button == MOUSE_R)
	{
		data->map->trans[X] += (x - data->mlx->last_click.axes[X]);
		data->map->trans[Y] += (y - data->mlx->last_click.axes[Y]);
		data->mlx->last_click.axes[X] = x;
		data->mlx->last_click.axes[Y] = y;
		ft_apply_and_draw(data->map, data->mlx);
	}
}

int	ft_mouse_move(int x, int y, t_data *data)
{
	ft_mouse_rots(x, y, data);
	ft_mouse_trans(x, y, data);
	return (0);
}

void	ft_scale_bts(int button, int x, int y, t_data *data)
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
	ft_apply_and_draw(data->map, data->mlx);
}

void	ft_save_pos_bts(int button, int x, int y, t_mlx_data *mlx)
{
	if (button == MOUSE_L || button == MOUSE_R)
	{
		mlx->button = button;
		mlx->last_click.axes[X] = x;
		mlx->last_click.axes[Y] = y;
	}
}

int	ft_mouse_press(int button, int x, int y, t_data *data)
{
	ft_scale_bts(button, x, y, data);
	ft_save_pos_bts(button, x, y, data->mlx);
	return (0);
}
