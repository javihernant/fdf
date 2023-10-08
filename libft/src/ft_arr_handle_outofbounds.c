/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_handle_outofbounds.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:24:55 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/28 13:20:41 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arr_handle_outofbounds(t_array *arr)
{
	while (arr->top * arr->msize >= arr->size)
	{
		arr->arr = ft_realloc(arr->arr, arr->size, arr->size * 2);
		if (!arr->arr)
			return (1);
		arr->size *= 2;
	}
	return (0);
}
