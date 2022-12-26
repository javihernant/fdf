/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:50:26 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:50:56 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

void	ft_scale_keys(int key, t_map *map)
{
	if (key == XK_plus)
	{
		map->scale *= 2;
	}
	else if (key == XK_minus)
	{
		map->scale *= 0.5;
	}
	else if (key == XK_comma)
	{
		map->zdiv *= 2;
	}
	else if (key == XK_period)
	{
		map->zdiv *= 0.5;
	}
}

void	ft_trans_keys(int key, float *trans)
{
	if (key == XK_Left)
		trans[X] -= TRANS_RATE;
	else if (key == XK_Right)
		trans[X] += TRANS_RATE;
	else if (key == XK_Down)
		trans[Y] += TRANS_RATE;
	else if (key == XK_Up)
		trans[Y] -= TRANS_RATE;
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
