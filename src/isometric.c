/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:35:38 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/10 20:40:07 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

void	ft_isometric(t_map *map)
{
	ft_rotate_x(map, 30);
	ft_rotate_y(map, 330);
	ft_rotate_z(map, 30);
}
