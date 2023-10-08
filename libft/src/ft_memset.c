/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:35:09 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/27 15:24:18 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buff;
	size_t			i;

	buff = b;
	i = 0;
	while (i < len)
	{
		buff[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
