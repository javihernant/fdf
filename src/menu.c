/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:26:44 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/09 12:19:52 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_utils.h"

#define MENU_YMIN 270
#define MENU_XMIN 50
#define LINE_H 30

static void	ft_draw_keys(int crd[2], t_mlx_data *mlx)
{
	ft_draw_str("Keys:", crd, COL_YELL, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Rotate X axis: Press a/d", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Rotate Y axis: Press w/s", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Rotate Z axis: Press z/x", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Translate X axis: Left / Right", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Translate Y axis: Up / Down", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Bend object: v/b", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Reduce altitude: ,", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Increase altitude: .", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Center: c", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Fit: f", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
}

static void	ft_draw_mouse(int crd[2], t_mlx_data *mlx)
{
	ft_draw_str("Mouse:", crd, COL_YELL, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Left click: Rotate X/Y", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Right click: Move object", crd, COL_WHTE, mlx);
	crd[Y] += LINE_H;
	ft_draw_str("Scroll down/up: Zoom in/out", crd, COL_WHTE, mlx);
}

void	ft_draw_controls(t_mlx_data *mlx)
{
	int	crd[2];

	crd[X] = MENU_XMIN;
	crd[Y] = MENU_YMIN;
	ft_draw_str("CONTROLS:", crd, COL_ORNG, mlx);
	crd[Y] += LINE_H;
	ft_draw_keys(crd, mlx);
	ft_draw_mouse(crd, mlx);
}

void	ft_draw_menu(t_mlx_data *mlx)
{
	ft_draw_controls(mlx);
}
