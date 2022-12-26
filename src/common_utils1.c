/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:35:28 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 14:31:16 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "fdf.h"

static int	ft_get_hexval(char c)
{
	char	*vals;
	int		i;

	vals = "0123456789abcdef";
	if (c >= 'A' && c <= 'F')
		c += 32;
	i = 0;
	while (vals[i] != '\0')
	{
		if (vals[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	ft_hex_atoi(char *str)
{
	int	v;

	if (!str)
		return (0xffffffff);
	v = 0;
	if (*str == ',')
		str++;
	else
		return (0xffffffff);
	str += 2;
	while (*str != '\0' && ft_get_hexval(*str) >= 0)
	{
		v = (v << 4) | ft_get_hexval(*str);
		str++;
	}
	return (v);
}

void	ft_error(void)
{
	ft_putstr_fd("Error!", 2);
	exit(1);
}

float	ft_midz(t_map *map)
{
	int		i;
	int		c;
	float	pz;
	float	res;

	i = 0;
	c = 0;
	res = 0;
	while (i < map->w * map->h)
	{
		pz = map->mat[i].axes[Z];
		if (pz != 0)
		{
			res += pz;
			c++;
		}
		i++;
	}
	return (res / c);
}

float	ft_get_maxz(t_map *map)
{
	int		i;
	float	pz;
	float	res;

	if (map->len <= 0)
		return (0);
	res = map->mat[0].axes[Z];
	i = 1;
	while (i < map->len)
	{
		pz = map->mat[i].axes[Z];
		if (pz > res)
			res = pz;
		i++;
	}
	return (res);
}
