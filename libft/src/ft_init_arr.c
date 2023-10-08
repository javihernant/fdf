/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:37:31 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/05 20:40:30 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_init_arr(t_array *arr, size_t n, size_t msize)
{
	arr->arr = malloc(msize * n);
	if (!arr->arr)
		return (1);
	arr->top = 0;
	arr->size = msize * n;
	arr->msize = msize;
	return (0);
}
