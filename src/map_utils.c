/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:16:57 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/01 18:50:31 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

int	ft_get_width(char *line)
{
	char	**values;
	int		i;	

	if (line == NULL)
		return (-1);
	values = ft_split(line, ' ');
	if (!values)
		return (-1);
	i = 0;
	while (values[i] != NULL)
	{
		free(values[i]);
		i++;
	}
	free(values);
	return (i);
}

void	ft_print_point(t_point *p)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_printf("%d,", p->axes[i]);
		i++;
	}
	ft_printf("%d", p->color);
}

void	ft_print_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			ft_print_point(&map->pts[i * map->w + j]);
			ft_printf(" ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_mod_point(int pt_idx, int val, int axis, t_map *map)
{
	map->pts[pt_idx].axes[axis] = val;
	if (val < map->axes_mins[axis])
		map->axes_mins[axis] = val;
	if (val > map->axes_maxs[axis])
		map->axes_maxs[axis] = val;
}
