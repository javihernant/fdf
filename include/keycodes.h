/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:23:38 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/21 10:42:29 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# include <X11/X.h>
# include <X11/keysym.h>

# define MOUSE_L 1
# define MOUSE_R 3
int	ft_handle_keys(int keycode, t_data *data);
int	ft_mouse_press(int button, int x, int y, t_data *data);
int	ft_mouse_release(int button, int x, int y, t_data *data);
int	ft_mouse_move(int x, int y, t_data *data);
#endif
