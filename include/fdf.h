/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:50:45 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/20 19:55:51 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft.h"

# define WIDTH 1920
# define HEIGHT 1080

# define X 0
# define Y 1
# define Z 2

# define INIT_SCALE 70
# define TRANS_RATE 50
# define MIN_DIST 100
# define ANG_RATE 10

# define COL_BLCK 0

typedef struct s_point {
	float	axes[3];
	int		color;
}	t_point;

typedef struct s_mlx_data {
	void	*mlx_ptr;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_point	last_click;
	int		button;
	//int		stroke;
}	t_mlx_data;

typedef struct s_map {
	int		w;
	int		h;
	int		zdiv;
	int		len;
	t_point	*pts;
	t_point	*mat;
	float	scale;
	float	trans[3];
	float	rots[3];
	float	brange;
}	t_map;

typedef struct s_data {
	t_mlx_data	*mlx;
	t_map		*map;
}	t_data;

#endif
