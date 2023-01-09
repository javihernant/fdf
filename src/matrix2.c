/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:50:46 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/09 11:51:21 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mat_trans(t_point *pts, int len, float vec[3])
{
	int		i;
	float	*axes;

	i = 0;
	while (i < len)
	{
		axes = pts[i].axes;
		axes[X] += vec[X];
		axes[Y] += vec[Y];
		i++;
	}
}
