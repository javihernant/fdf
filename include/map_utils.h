/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:18:25 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/19 14:26:30 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H
# include "fdf.h"
# include "matrix.h"

int		ft_get_width(char *line);
void	ft_print_point(t_point *p);
void	ft_print_map(t_map *map);
void	ft_apply_and_draw(t_map *map, t_mlx_data *data);
int		ft_parse_map(char *path, t_map *map);
void	ft_zoom_center(t_map *map, t_point *ms_pos);
void	ft_isometric(t_map *map);
void	ft_scale_pts(t_map *map, float scale, t_point *prev_cntr);
void	ft_rotate(t_map *map);
void	ft_print_map_data(t_map *map);
void	ft_bend(t_map *map);
#endif
