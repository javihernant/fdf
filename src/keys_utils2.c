/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:54:04 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:55:14 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycodes.h"
#include "fdf.h"
#include "prog_utils.h"
#include "map_utils.h"

void	ft_misc_keys(int key, t_data *data)
{
	if (key == XK_c)
		ft_center(data->map->trans);
	else if (key == XK_f)
		ft_fit(data->map);
	else if (key == XK_g)
	{
		if (data->map->view == DFLT_VW)
			data->map->view = SPHR_VW;
		else
			data->map->view = DFLT_VW;
	}
	else if (key == XK_r)
	{
		ft_reset_props(data->map);
		ft_fit(data->map);
	}
	else if (key == XK_Escape)
		ft_quit_prog(data);
}
