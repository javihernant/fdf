/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:52:25 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/21 11:27:54 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "map_utils.h"

void	ft_free_mlxdata(t_mlx_data *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	if (mlx->img_addr != NULL)
		mlx_destroy_image (mlx->mlx_ptr, mlx->img_addr);
}

void	ft_quit_prog(t_data *data)
{
	ft_free_mlxdata(data->mlx);
	ft_free_map(data->map);
	exit(0);
}

int	ft_mlx_init(t_mlx_data *mlx)
{
	int	rc;

	mlx->win = NULL;
	mlx->img = NULL;
	mlx->img_addr = NULL;
	mlx->mlx_ptr = mlx_init();
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
