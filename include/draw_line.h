/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:20:49 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/09 11:21:59 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define MLX_UTILS_H

void	ft_copy_pt(t_point *tmp, t_point *a);
void	ft_calc_inc(int *inc, float *dif);
void	ft_2pts_dif(float dif[2], t_point *a, t_point *b);
void	ft_calc_color_low(t_point *curr, int width, int col_a, int col_b);
void	ft_calc_color_high(t_point *curr, int width, int col_a, int col_b);
#endif
