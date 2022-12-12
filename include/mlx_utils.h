/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:19:19 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/03 23:14:56 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

int		ft_mlx_init(t_mlx_data *data);
void	ft_free_mlxdata(t_mlx_data *data);
void	ft_pixel_put(t_point *point, t_mlx_data *data);
void	ft_draw_line(t_point *a, t_point *b, t_mlx_data *data);
int		ft_get_alpha(int col);
int		ft_get_red(int col);
int		ft_get_green(int col);
int		ft_get_blue(int col);
void	ft_set_color(int color, t_mlx_data *data);
void	ft_update_img(t_mlx_data *mlx_data);
#endif
