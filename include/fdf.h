/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:50:45 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/23 20:28:23 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_bytes;
	int		endian;
}	t_data;

void	ft_mlx_pixel_put(t_data *data, void *mlx, int x, int y, int color);
int		**ft_parse_maps(char *path, int *width, int *height);
#endif
