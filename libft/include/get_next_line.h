/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:01:10 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/08 18:04:25 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 50
# define BUFFER_SIZE 1024
# include <unistd.h>
# include <stdlib.h>

int		ft_find_nl(char buffer[BUFFER_SIZE]);
int		ft_linecpy(char *dst, char *src);
#endif
