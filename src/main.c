/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:13:09 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/13 20:56:28 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "map_utils.h"
#include "common_utils.h"
#include "mlx_utils.h"
#include "keycodes.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_data		data;
	t_map		map;
	t_mlx_data	mlx;

	if (argc != 2)
	{
		ft_printf("%s: <map.fdf>\n", argv[0]);
		return (0);
	}
	if (ft_parse_map(argv[1], &map) != 0)
		ft_error();
	if (ft_mlx_init(&mlx) != 0)
		ft_error();
	ft_apply_and_draw(&map, &mlx);
	data.mlx = &mlx;
	data.map = &map;
	//mlx_mouse_hook(mlx.win, ft_handle_key, &data);
	//mlx_hook(mlx.win, 5, ButtonReleaseMask, ft_mouse_release, &data);
	mlx_hook(mlx.win, 6, Button1MotionMask, ft_mouse_move, &data);
	mlx_key_hook(mlx.win, ft_handle_key, &data);
	mlx_mouse_hook(mlx.win, ft_mouse_press, &data);
	mlx_loop(mlx.mlx_ptr);
	free(map.pts);
	return (0);
}
