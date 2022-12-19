/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:23:38 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/19 15:29:45 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# include <X11/X.h>
# define KEY_ESC     53
# define KEY_1       18
# define KEY_2       19
# define KEY_3       20
# define KEY_4       21
# define KEY_5       23
# define KEY_6       22
# define KEY_7       26
# define KEY_8       28
# define KEY_9       25
# define KEY_0       29
# define KEY_PLUS    30
# define KEY_MIN     44
# define KEY_PLUS2   69
# define KEY_MIN2    78
# define KEY_A       0
# define KEY_S       1
# define KEY_D       2
# define KEY_F       3
# define KEY_H       4
# define KEY_G       5
# define KEY_Z       6
# define KEY_X       7
# define KEY_C       8
# define KEY_V       9
# define KEY_B       11
# define KEY_Q       12
# define KEY_W       13
# define KEY_E       14
# define KEY_R       15
# define KEY_Y       16
# define KEY_T       17
# define KEY_U       32
# define KEY_I       34
# define KEY_P       35
# define KEY_L       37
# define KEY_J       38
# define KEY_K       40
# define KEY_N       45
# define KEY_M       46
# define KEY_TAB     48
# define KEY_LEFT    123
# define KEY_RIGHT   124
# define KEY_DOWN    125
# define KEY_UP      126
# define KEY_CTRL    256
# define KEY_CMD     259

# include <X11/keysym.h>

int	ft_handle_key(int keycode, t_data *data);
int	ft_mouse_press(int button, int x, int y, t_data *data);
int	ft_mouse_release(int button, int x, int y, t_data *data);
int	ft_mouse_move(int x, int y, t_data *data);
#endif
