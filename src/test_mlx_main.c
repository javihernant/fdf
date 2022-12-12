/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:09:12 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/28 19:55:17 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_utils.h"

int	main(void)
{
	t_mlx_data	data;
	t_point		p;
	t_point		b;
	int			i;
	int			j;

	ft_mlx_init(&data);
	p.x = 10;
	p.y = 50;
	p.color = 0x00500000;
	b.x = 900;
	b.y = 500;
	b.color = 0x00ff00ff;
	//ft_pixel_put(&p, &data);
	ft_draw_line(&p, &b, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	/*
	j = 0;
	while (j < 1080)
	{
		i = 0;
		while (i < 1920)
		{
			p.x = i;
			p.y = j;
			p.color = 0x00ff0000;
			ft_pixel_put(&p, &data);
			i++;
		}
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
		j++;
	}	
	*/
	mlx_loop(data.mlx_ptr);
	return (0);
}
