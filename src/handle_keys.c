/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:22:20 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/21 11:12:46 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"
#include "map_utils.h"
#include "libft.h"
#include "prog_utils.h"

void	ft_center(t_map *map)
{
	map->trans[X] = WIDTH / 2;
	map->trans[Y] = HEIGHT / 2;
}

/* Check if all of the points coords are within the screen resolution */ 
int	ft_all_points_in(t_map *map)
{
	int		i;
	t_point	*pt;

	ft_apply_props(map);
	i = 0;
	while (i < map->len)
	{
		pt = &map->pts[i];
		if (pt->axes[X] >= WIDTH || pt->axes[X] < 0)
			return (0);
		if (pt->axes[Y] >= HEIGHT || pt->axes[Y] < 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_fit(t_map *map)
{
	ft_center(map);
	map->scale = 1;
	while (ft_all_points_in(map))
	{
		map->scale += 2;
	}
	map->scale -= 2;
}

void	ft_scale_keys(int key, float *scale)
{
	if (key == XK_plus)
	{
		*scale *= 2;
	}
	else if (key == XK_minus)
	{
		*scale *= 0.5;
	}
}

void	ft_trans_keys(int key, float *trans)
{
	if (key == XK_Left)
	{
		trans[X] -= TRANS_RATE;
	}
	else if (key == XK_Right)
	{
		trans[X] += TRANS_RATE;
	}
	else if (key == XK_Down)
	{
		trans[Y] += TRANS_RATE;
	}
	else if (key == XK_Up)
	{
		trans[Y] -= TRANS_RATE;
	}
}

void	ft_rots_keys(int key, float *rots)
{
	if (key == XK_d)
		rots[Y] += ANG_RATE;
	else if (key == XK_a)
		rots[Y] -= ANG_RATE;
	else if (key == XK_w)
		rots[X] -= ANG_RATE;
	else if (key == XK_s)
		rots[X] += ANG_RATE;
	else if (key == XK_z)
		rots[Z] -= ANG_RATE;
	else if (key == XK_x)
		rots[Z] += ANG_RATE;
}

void	ft_bend_keys(int key, float *brange)
{
	if (key == XK_b)
		*brange += 0.0002;
	else if (key == XK_v)
		*brange -= 0.0002;
}

void	ft_projs_keys(int key, float *rots)
{
	if (key == XK_i)
	{
		rots[X] = 30;
		rots[Y] = 330;
		rots[Z] = 30;
	}
	else if (key == XK_1)
	{
		rots[X] = 90;
		rots[Y] = 0;
		rots[Z] = 0;
	}
	else if (key == XK_2)
	{
		rots[X] = 0;
		rots[Y] = 90;
		rots[Z] = 0;
	}
	else if (key == XK_3)
	{
		rots[X] = 0;
		rots[Y] = 0;
		rots[Z] = 0;
	}
}

void	ft_misc_keys(int key, t_data *data)
{
	if (key == XK_c)
		ft_center(data->map);
	else if (key == XK_f)
		ft_fit(data->map);
	else if (key == XK_r)
		ft_reset_props(data->map);
	else if (key == XK_Escape)
		ft_quit_prog(data);
}

int	ft_handle_keys(int keycode, t_data *data)
{
	ft_scale_keys(keycode, &data->map->scale);
	ft_trans_keys(keycode, data->map->trans);
	ft_rots_keys(keycode, data->map->rots);
	ft_projs_keys(keycode, data->map->rots);
	ft_bend_keys(keycode, &data->map->brange);
	ft_misc_keys(keycode, data);
	ft_apply_and_draw(data->map, data->mlx);
	return (0);
}
