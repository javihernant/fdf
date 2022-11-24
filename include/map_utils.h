/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:18:25 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/24 18:04:28 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

int		ft_get_width(char *line);
void	ft_free_maps(int ***maps);
void	ft_print_maps(int **maps, int width, int height);
#endif
