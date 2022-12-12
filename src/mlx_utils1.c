/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:54:20 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/11 15:59:14 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	ft_free_mlxdata(t_mlx_data *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	free(mlx->mlx_ptr);
	free(mlx->img);
	free(mlx->img_addr);
	mlx->mlx_ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->img_addr = NULL;
}

int	ft_mlx_init(t_mlx_data *mlx)
{
	int	rc;

	mlx->win = NULL;
	mlx->img = NULL;
	mlx->img_addr = NULL;
	mlx->mlx_ptr = mlx_init();
	mlx->mouse_held = 0;
	rc = 0;
	if (!mlx->mlx_ptr)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT,
			"Hello world!");
	if (!mlx->win)
		rc = 1;
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img)
		rc = 1;
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (!mlx->img_addr)
		rc = 1;
	if (rc != 0)
		ft_free_mlxdata(mlx);
	return (rc);
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
	t_point	pt;
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pt.axes[X] = j;
			pt.axes[Y] = i;
			pt.color = color;
			ft_pixel_put(&pt, mlx);
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
