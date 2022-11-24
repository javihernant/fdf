/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:18:24 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/24 13:24:14 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map_utils.h"
#include "fdf.h"

int	main(int argc, char *argv[])
{
	int	**maps;
	int	width;
	int	height;

	if (argc != 2)
	{
		ft_printf("%s: <map.fdf>\n", argv[0]);
		return (0);
	}
	maps = ft_parse_maps(argv[1], &width, &height);
	ft_print_maps(maps, width, height);
	ft_free_maps(&maps);
	return (0);
}
