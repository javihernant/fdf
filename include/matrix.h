/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:39:02 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/19 15:30:27 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "fdf.h"

void	ft_rotate_x(t_point *map, size_t len, float angle);
void	ft_rotate_y(t_point *map, size_t len, float angle);
void	ft_rotate_z(t_point *map, size_t len, float angle);
//t_point	ft_central_pt(t_point *mat, size_t len);
void	ft_mat_trans(t_point *pts, size_t len, float vec[3]);
void	ft_mat_scale(t_point *pts, size_t len, float scale);
#endif
