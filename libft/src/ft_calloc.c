/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:38:04 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/27 18:07:13 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc
#include "libft.h" //ft_bzero
#include <stdint.h> //SIZE_MAX

void	*ft_calloc(size_t count, size_t size)
{
	void	*buf;

	if (count && (SIZE_MAX / count < size))
		return (0);
	buf = malloc(size * count);
	if (!buf)
		return (0);
	ft_bzero(buf, size * count);
	return (buf);
}
