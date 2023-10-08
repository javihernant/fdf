/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:03:45 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/08 13:39:59 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_nl(char buffer[BUFFER_SIZE])
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_linecpy(char *dst, char *src)
{
	int	i;

	if (src == 0)
		return (0);
	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dst[i++] = '\n';
	dst[i] = '\0';
	return (i);
}
