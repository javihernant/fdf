/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:22:55 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 18:37:09 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map_utils.h"
#include "common_utils.h"

int	ft_check_format(char *path)
{
	int		i;
	int		j;
	char	*fmt;

	fmt = ".fdf";
	i = ft_strlen(path);
	if (i == 0 || i < 4)
		return (1);
	i -= 1;
	j = 3;
	while (j >= 0)
	{
		if (path[i] != fmt[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

static void	ft_color_pt(int *color, int ptg)
{
	if (ptg == 0)
		*color = COL_0;
	else if (ptg < 20)
		*color = COL_1;
	else if (ptg < 40)
		*color = COL_2;
	else if (ptg < 60)
		*color = COL_3;
	else if (ptg < 80)
		*color = COL_4;
	else
		*color = COL_5;
}

void	ft_color_pts(t_map *map)
{
	int		i;
	t_point	*pt;
	int		ptg;

	i = 0;
	while (i < map->len)
	{
		pt = &map->mat[i];
		ptg = (pt->axes[Z] / (float) map->zmax) * 100;
		ft_color_pt(&pt->color, ptg);
		i++;
	}
}

void	ft_mat_to_orig(t_map *map)
{
	float	vec[3];

	vec[X] = -map->w / 2;
	vec[Y] = -map->h / 2;
	vec[Z] = 0;
	ft_mat_trans(map->mat, map->w * map->h, vec);
}

void	ft_init_mapdata(t_map *map)
{
	map->zmax = ft_get_maxz(map);
	if (!map->has_color)
		ft_color_pts(map);
	ft_reset_props(map);
	ft_mat_to_orig(map);
}
