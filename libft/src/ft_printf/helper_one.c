/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:26:17 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/28 13:52:57 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_opts(t_options *opts)
{
	opts->flags = 0;
	opts->width = 0;
	opts->precision = -1;
	opts->specifier = 0;
}

char	ft_get_digit(size_t idx, char specifier)
{
	char	*digits;
	char	*digits_mayus;
	char	dig;

	digits = "0123456789abcdef";
	digits_mayus = "0123456789ABCDEF";
	if (specifier == 'x' || specifier == 'u' || specifier == 'p')
		dig = digits[idx];
	else
		dig = digits_mayus[idx];
	return (dig);
}

void	ft_arr_handle_outofbounds_depr(t_array *arr)
{
	if (arr->top >= arr->size)
	{
		arr->arr = ft_realloc(arr->arr, arr->size, arr->size + 100);
		arr->size += 100;
	}
}
