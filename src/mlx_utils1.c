/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:54:20 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/29 18:58:04 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	ft_free_mlxdata(t_mlx_data *data)
{
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->mlx_ptr);
	free(data->img);
	free(data->img_addr);
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->img_addr = NULL;
}

int	ft_mlx_init(t_mlx_data *data)
{
	int	rc;

	data->w = 1920;
	data->h = 1080;
	data->mlx_win = NULL;
	data->img = NULL;
	data->img_addr = NULL;
	data->mlx_ptr = mlx_init();
	rc = 0;
	if (!data->mlx_ptr)
		return (1);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->w, data->h,
			"Hello world!");
	if (!data->mlx_win)
		rc = 1;
	data->img = mlx_new_image(data->mlx_ptr, data->w, data->h);
	if (!data->img)
		rc = 1;
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->size_line, &data->endian);
	if (!data->img_addr)
		rc = 1;
	if (rc != 0)
		ft_free_mlxdata(data);
	return (rc);
}

void	ft_pixel_put(t_point *point, t_mlx_data *data)
{
	char	*dst;

	dst = data->img_addr + (point->y * data->size_line + point->x
			* (data->bits_per_pixel / 8));
	if (data->endian == 1)
	{
		dst[0] = (point->color >> 24);
		dst[1] = (point->color >> 16) & 0xFF;
		dst[2] = (point->color >> 8) & 0xFF;
		dst[3] = (point->color) & 0xFF;
	}
	else if (data->endian == 0)
	{
		dst[0] = (point->color) & 0xFF;
		dst[1] = (point->color >> 8) & 0xFF;
		dst[2] = (point->color >> 16) & 0xFF;
		dst[3] = (point->color >> 24);
	}
}

int	ft_get_alpha(int col)
{
	return ((col >> 24) & 0xff);
}

int	ft_get_red(int col)
{
	return ((col >> 16) & 0xff);
}
