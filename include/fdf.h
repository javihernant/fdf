/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:50:45 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 19:14:05 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft.h"

# define DFLT_VW 0
# define SPHR_VW 1

# define WIDTH 1920
# define HEIGHT 1080
# define PANEL_W 480 
# define PADDING 20 

# define X 0
# define Y 1
# define Z 2
# define PHI 0
# define THETA 1

# define INIT_SCALE 70
# define TRANS_RATE 50
# define MIN_DIST 100
# define ANG_RATE 10

# define COL_BLCK 0
# define COL_WHTE 0xffffffff
# define COL_DRKBLUE 0xaf040f3c
# define COL_ORNG 0x00ffa500
# define COL_YELL 0x00ffff00
# define COL_0 0x000000ff
# define COL_1 0x0000ff00
# define COL_2 0x00ffff00
# define COL_3 0x00ffa500
# define COL_4 0x00e389b9
# define COL_5 0x00ff0000

typedef struct s_point {
	float	axes[3];
	float	sph[2];
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
}	t_mlx_data;

typedef struct s_map {
	int		w;
	int		h;
	int		zmax;
	float	zdiv;
	int		len;
	int		view;
	int		has_color;
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
