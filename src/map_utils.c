/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:16:57 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/24 18:03:26 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

void	ft_free_maps(int ***maps)
{
	free((*maps)[0]);
	free((*maps)[1]);
	free(*maps);
	*maps = NULL;
}

static void	ft_print_map(int *map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%d ", map[i * width + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_print_maps(int **maps, int width, int height)
{
	ft_printf("Values:\n");
	ft_print_map(maps[0], width, height);
	ft_printf("Colors:\n");
	ft_print_map(maps[1], width, height);
}
