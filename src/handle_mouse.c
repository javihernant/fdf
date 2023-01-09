/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:43:57 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/09 12:09:22 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

int	ft_mouse_move(int x, int y, t_data *data)
{
	ft_mouse_rots(x, y, data);
	ft_mouse_trans(x, y, data);
	return (0);
}

int	ft_mouse_press(int button, int x, int y, t_data *data)
{
	ft_scale_bts(button, x, y, data);
	ft_save_pos_bts(button, x, y, data->mlx);
	return (0);
}
