/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:18:25 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/10 20:32:52 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H
# include "fdf.h"

int		ft_get_width(char *line);
void	ft_print_point(t_point *p);
void	ft_print_map(t_map *map);
void	ft_draw_map(t_map *map, t_mlx_data *data);
int		ft_parse_map(char *path, t_map *map);
void	ft_scale_map(t_map *map, float scale, t_point *prev_cntr);
void	ft_translate_map(t_map *map, t_point *vec);
void	ft_rotate_x(t_map *map, float angle);
void	ft_rotate_y(t_map *map, float angle);
void	ft_rotate_z(t_map *map, float angle);
void	ft_zoom_center(t_map *map, t_point *ms_pos);
void	ft_center_map(t_map *map);
void	ft_isometric(t_map *map);
void	ft_mod_point(int pt_idx, int val, int axis, t_map *map);
#endif
