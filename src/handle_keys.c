/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:22:20 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/19 14:59:46 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"
#include "map_utils.h"
#include "libft.h"
#include "mlx_utils.h"

int	ft_handle_key(int keycode, t_data *data)
{
	if (keycode == XK_plus)
	{
		data->map->scale *= 2;
	}
	else if (keycode == XK_minus)
	{
		data->map->scale *= 0.5;
	}
	else if (keycode == XK_Left)
	{
		data->map->trans[X] -= TRANS_RATE;
	}
	else if (keycode == XK_Right)
	{
		data->map->trans[X] += TRANS_RATE;
	}
	else if (keycode == XK_Down)
	{
		data->map->trans[Y] += TRANS_RATE;
	}
	else if (keycode == XK_Up)
	{
		data->map->trans[Y] -= TRANS_RATE;
	}
	else if (keycode == XK_d)
	{
		data->map->rots[Y] += ANG_RATE;
	}
	else if (keycode == XK_a)
	{
		data->map->rots[Y] -= ANG_RATE;
	}
	else if (keycode == XK_w)
	{
		data->map->rots[X] -= ANG_RATE;
	}
	else if (keycode == XK_s)
	{
		data->map->rots[X] += ANG_RATE;
	}
	else if (keycode == XK_z)
	{
		data->map->rots[Z] -= ANG_RATE;
	}
	else if (keycode == XK_x)
	{
		data->map->rots[Z] += ANG_RATE;
	}
	else if (keycode == XK_i)
	{
		data->map->rots[X] = 30;
		data->map->rots[Y] = 330;
		data->map->rots[Z] = 30;
	}
	else if (keycode == XK_b)
	{
		data->map->brange += 0.0002;
	}
	else if (keycode == XK_v)
	{
		data->map->brange -= 0.0002;
	}
	else if (keycode == XK_1)
	{
		data->map->rots[X] = 90;
		data->map->rots[Y] = 0;
		data->map->rots[Z] = 0;
	}
	else if (keycode == XK_2)
	{
		data->map->rots[X] = 0;
		data->map->rots[Y] = 90;
		data->map->rots[Z] = 0;
	}
	else if (keycode == XK_3)
	{
		data->map->rots[X] = 0;
		data->map->rots[Y] = 0;
		data->map->rots[Z] = 0;
	}
	ft_apply_and_draw(data->map, data->mlx);
	return (0);
}
