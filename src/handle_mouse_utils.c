/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:02:49 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/09 12:09:26 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"
#include "map_utils.h"

void	ft_save_pos_bts(int button, int x, int y, t_mlx_data *mlx)
{
	if (button == MOUSE_L || button == MOUSE_R)
	{
		mlx->button = button;
		mlx->last_click.axes[X] = x;
		mlx->last_click.axes[Y] = y;
	}
}

void	ft_scale_bts(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_SCROLL_UP)
	{
		data->map->scale *= 0.5;
		data->map->trans[X] *= 0.5;
		data->map->trans[Y] *= 0.5;
		data->map->trans[X] += (x - x * 0.5);
		data->map->trans[Y] += (y - y * 0.5);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		data->map->scale *= 2;
		data->map->trans[X] *= 2;
		data->map->trans[Y] *= 2;
		data->map->trans[X] += (x - x * 2);
		data->map->trans[Y] += (y - y * 2);
	}
	ft_apply_and_draw(data->map, data->mlx);
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
