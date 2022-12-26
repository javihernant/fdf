/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:42:27 by jahernan          #+#    #+#             */
/*   Updated: 2022/12/21 20:57:40 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_UTILS_H
# define COMMON_UTILS_H

int		ft_hex_atoi(char *str);
void	ft_error(void);
int		ft_abs(int num);
float	ft_midz(t_map *map);
float	ft_get_maxz(t_map *map);
float	ft_arr_mult(float *arr, int len, int sc);
#endif
