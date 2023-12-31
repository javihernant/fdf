/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:18:25 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/22 23:55:35 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H
# include "fdf.h"
# include "matrix.h"

void	ft_apply_props(t_map *map);
void	ft_free_map(t_map *map);
void	ft_apply_and_draw(t_map *map, t_mlx_data *data);
int		ft_parse_map(char *path, t_map *map);
void	ft_zoom_center(t_map *map, t_point *ms_pos);
void	ft_isometric(t_map *map);
void	ft_scale_pts(t_map *map, float scale, t_point *prev_cntr);
void	ft_rotate(t_map *map);
void	ft_bend(t_map *map);
void	ft_reset_props(t_map *map);
void	ft_zdiv(t_map *map);
void	ft_zmult(t_point *mat, int len, int sc);
void	ft_center(float *trans);
void	ft_fit(t_map *map);
void	ft_draw_menu(t_mlx_data *mlx);
void	ft_spherize(t_map *map);
#endif
