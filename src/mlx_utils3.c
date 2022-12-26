/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:42:46 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:43:17 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	ft_draw_nbr(int nbr, int crd[2], int col, t_mlx_data *mlx)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(mlx->mlx_ptr, mlx->win, crd[X], crd[Y], col, str);
	free (str);
}

void	ft_draw_str(char *str, int crd[2], int col, t_mlx_data *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win, crd[X], crd[Y], col, str);
}
