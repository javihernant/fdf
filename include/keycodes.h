/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:23:38 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/09 12:07:08 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "fdf.h"

# define MOUSE_L 1
# define MOUSE_R 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

int		ft_handle_keys(int keycode, t_data *data);
void	ft_scale_keys(int key, t_map *map);
void	ft_trans_keys(int key, float *trans);
void	ft_rots_keys(int key, float *rots);
void	ft_bend_keys(int key, float *brange);
void	ft_projs_keys(int key, float *rots);
void	ft_misc_keys(int key, t_data *data);
int		ft_mouse_press(int button, int x, int y, t_data *data);
void	ft_save_pos_bts(int button, int x, int y, t_mlx_data *mlx);
void	ft_scale_bts(int button, int x, int y, t_data *data);
int		ft_mouse_release(int button, int x, int y, t_data *data);
int		ft_mouse_move(int x, int y, t_data *data);
void	ft_mouse_rots(int x, int y, t_data *data);
void	ft_mouse_trans(int x, int y, t_data *data);
#endif
