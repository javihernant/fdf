/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:44:14 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/24 13:08:36 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*dst_cpy;
	char	*src_cpy;
	size_t	i;

	dst_cpy = (char *) dst;
	src_cpy = (char *) src;
	i = 0;
	if ((dst == 0 && src == 0) || n == 0)
		return (dst);
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
