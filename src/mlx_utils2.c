/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:26:25 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:42:23 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_utils.h"

int	ft_get_alpha(int col)
{
	return ((col >> 24) & 0xff);
}

int	ft_get_red(int col)
{
	return ((col >> 16) & 0xff);
}

int	ft_get_green(int col)
{
	return ((col >> 8) & 0xff);
}

int	ft_get_blue(int col)
{
	return (col & 0xff);
}

