/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:18:54 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/29 13:16:35 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *b, size_t old_size, size_t size)
{
	void	*bf;

	if (size == 0)
	{
		free(b);
		return (0);
	}
	bf = malloc(size);
	if (!bf)
	{
		free(b);
		return (0);
	}
	ft_memcpy(bf, b, old_size);
	free(b);
	return (bf);
}
