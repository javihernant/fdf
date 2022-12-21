/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:54:20 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/21 10:52:40 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	ft_set_px_col(char *addr, int color, int endian)
{
	if (endian == 1)
	{
		addr[0] = (color >> 24);
		addr[1] = (color >> 16) & 0xFF;
		addr[2] = (color >> 8) & 0xFF;
		addr[3] = (color) & 0xFF;
	}
	else if (endian == 0)
	{
		addr[0] = (color) & 0xFF;
		addr[1] = (color >> 8) & 0xFF;
		addr[2] = (color >> 16) & 0xFF;
		addr[3] = (color >> 24);
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
	if (mlx->endian == 1)
	{
		dst[0] = (point->color >> 24);
		dst[1] = (point->color >> 16) & 0xFF;
		dst[2] = (point->color >> 8) & 0xFF;
		dst[3] = (point->color) & 0xFF;
	}
	else if (mlx->endian == 0)
	{
		dst[0] = (point->color) & 0xFF;
		dst[1] = (point->color >> 8) & 0xFF;
		dst[2] = (point->color >> 16) & 0xFF;
		dst[3] = (point->color >> 24);
	}
}

void	ft_set_color(int color, t_mlx_data *mlx)
{
	int		i;
	int		j;
	char	*addr;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			addr = &mlx->img_addr[(i * mlx->size_line) + j * (mlx->bits_per_pixel / 8)];
			addr[0] = color;
			addr[1] = color;
			addr[2] = color;
			addr[3] = color;
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
