/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:58:01 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/26 18:56:55 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

static void	ft_move_backwards(char *dst, char *src, size_t len)
{
	int	i;

	i = ((int) len) - 1;
	while (i >= 0)
	{
		dst[i] = src[i];
		i--;
	}
}

static void	ft_move(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_cpy;
	char	*src_cpy;

	dst_cpy = (char *) dst;
	src_cpy = (char *) src;
	if (len == 0 || (src == 0 && dst == 0))
		return (dst);
	if (dst > src)
	{
		ft_move_backwards(dst_cpy, src_cpy, len);
	}
	else
	{
		ft_move(dst_cpy, src_cpy, len);
	}
	return (dst);
}
