/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_usig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:40:50 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/28 14:01:40 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_store_usig_nums(unsigned int num, t_array *arr,
	t_options *opts)
{
	int		b;

	b = 10;
	if (opts->specifier == 'x' || opts->specifier == 'X')
		b = 16;
	if (num == 0)
		opts->flags &= ~HSH_F;
	if (opts->precision == 0 && num == 0)
		return ;
	while (1)
	{
		ft_arr_handle_outofbounds_depr(arr);
		((char *) arr->arr)[arr->top] = ft_get_digit(num % b, opts->specifier);
		opts->precision -= 1;
		opts->width -= 1;
		num /= b;
		(arr->top)++;
		if (num == 0)
			break ;
	}
}

char	*ft_convert_usig(t_options *opts, va_list args)
{
	unsigned int	num;
	t_array			arr;

	num = va_arg(args, unsigned int);
	arr.size = 100;
	arr.top = 0;
	arr.arr = malloc(arr.size);
	if (!arr.arr)
		return (0);
	ft_store_usig_nums(num, &arr, opts);
	if ((opts->flags & ZER_F) != 0)
		ft_store_width(&arr, 0, opts);
	else
		ft_store_precision(&arr, opts);
	ft_store_sign(&arr, 0, opts);
	if ((opts->flags & MIN_F) == 0)
		ft_store_width(&arr, 0, opts);
	ft_arr_handle_outofbounds_depr(&arr);
	((char *)arr.arr)[arr.top] = '\0';
	ft_strrev((char *) arr.arr);
	return ((char *)arr.arr);
}
