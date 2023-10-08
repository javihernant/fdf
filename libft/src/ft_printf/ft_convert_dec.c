/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:03:47 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/28 13:59:35 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_store_nums(long int num, t_array *arr, t_options *opts)
{
	if (num < 0)
		num = -num;
	if (opts->precision == 0 && num == 0)
		return ;
	while (1)
	{
		ft_arr_handle_outofbounds_depr(arr);
		((char *) arr->arr)[arr->top] = '0' + (num % 10);
		opts->precision -= 1;
		opts->width -= 1;
		num /= 10;
		(arr->top)++;
		if (num == 0)
			break ;
	}
}

char	*ft_convert_dec(t_options *opts, va_list args)
{
	long int	num;
	t_array		arr;

	num = (long int) va_arg(args, int);
	arr.size = 100;
	arr.top = 0;
	arr.arr = malloc(arr.size);
	if (!arr.arr)
		return (0);
	ft_store_nums(num, &arr, opts);
	if ((opts->flags & ZER_F) != 0)
		ft_store_width(&arr, num < 0, opts);
	else
		ft_store_precision(&arr, opts);
	ft_store_sign(&arr, num < 0, opts);
	if ((opts->flags & MIN_F) == 0)
		ft_store_width(&arr, 0, opts);
	ft_arr_handle_outofbounds_depr(&arr);
	((char *)arr.arr)[arr.top] = '\0';
	ft_strrev((char *) arr.arr);
	return ((char *)arr.arr);
}
