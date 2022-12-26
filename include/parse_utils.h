/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:23:21 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/23 18:42:39 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

int		ft_check_format(char *path);
void	ft_color_pts(t_map *map);
void	ft_mat_to_orig(t_map *map);
int		ft_fill_mat(t_map *map, char *path);
int		ft_init_w_and_h(char *path, t_map *map);
void	ft_init_mapdata(t_map *map);
#endif
