/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:22:20 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:56:21 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"
#include "map_utils.h"

int	ft_handle_keys(int keycode, t_data *data)
{
	ft_scale_keys(keycode, data->map);
	ft_trans_keys(keycode, data->map->trans);
	ft_rots_keys(keycode, data->map->rots);
	ft_projs_keys(keycode, data->map->rots);
	ft_bend_keys(keycode, &data->map->brange);
	ft_misc_keys(keycode, data);
	ft_apply_and_draw(data->map, data->mlx);
	return (0);
}
