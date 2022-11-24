/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:09:12 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/22 17:53:59 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	i,j;

	mlx = mlx_init();
	if (!mlx)
		return (0);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_bytes,
			&img.endian);
	j = 0;
	while (j < 1080)
	{
		i = 0;
		while (i < 1920)
		{
			ft_mlx_pixel_put(&img, mlx, i, j, 0x00FF0000);
			i++;
		}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		j++;
	}	
	mlx_loop(mlx);
	return (0);
}
