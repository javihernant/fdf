/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:18:24 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/26 18:44:54 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map_utils.h"
#include "fdf.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("%s: <map.fdf>\n", argv[0]);
		return (0);
	}
	ft_parse_map(argv[1], &map);
	ft_print_map(&map);
	free(map.pts);
	return (0);
}
