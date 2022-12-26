/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:54:20 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/26 23:07:10 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	ft_set_color(char *dst, int color, int endian)
{
	if (endian == 1)
	{
		dst[0] = (color >> 24);
		dst[1] = (color >> 16) & 0xFF;
		dst[2] = (color >> 8) & 0xFF;
		dst[3] = (color) & 0xFF;
	}
	else if (endian == 0)
	{
		dst[0] = (color) & 0xFF;
		dst[1] = (color >> 8) & 0xFF;
		dst[2] = (color >> 16) & 0xFF;
		dst[3] = (color >> 24);
	}
}

void	ft_pixel_put(t_point *point, t_mlx_data *mlx)
{
	char	*dst;

	if (point->axes[X] < 0 || point->axes[X] >= WIDTH || point->axes[Y] < 0
		|| point->axes[Y] >= HEIGHT)
		return ;
	dst = mlx->img_addr + ((int) point->axes[Y] * mlx->size_line
			+ (int) point->axes[X] * (mlx->bits_per_pixel / 8));
	ft_set_color(dst, point->color, mlx->endian);
}

void	ft_set_bg(t_mlx_data *mlx)
{
	int		i;
	int		j;
	char	*addr;
	int		color;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			addr = &mlx->img_addr[(i * mlx->size_line) \
					+ j * (mlx->bits_per_pixel / 8)];
			if (j < PANEL_W)
				color = COL_DRKBLUE;
			else
				color = COL_BLCK;
			ft_set_color(addr, color, mlx->endian);
			j++;
		}
		i++;
	}
}

void	ft_update_img(t_mlx_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img, 0, 0);
}
