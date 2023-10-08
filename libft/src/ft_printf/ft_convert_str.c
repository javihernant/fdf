/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:49:17 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/28 14:01:06 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static void	ft_store_str(t_array *arr, const char *str, t_options *opts)
{
	while ((opts->precision > 0) && str[arr->top] != '\0')
	{
		ft_arr_handle_outofbounds_depr(arr);
		((char *)arr->arr)[arr->top] = str[arr->top];
		arr->top++;
		opts->width -= 1;
		opts->precision -= 1;
	}
	ft_arr_handle_outofbounds_depr(arr);
	((char *)arr->arr)[arr->top] = '\0';
	ft_strrev((char *)arr->arr);
	if ((opts->flags & MIN_F) == 0)
		ft_store_width(arr, 0, opts);
	ft_arr_handle_outofbounds_depr(arr);
	((char *)arr->arr)[arr->top] = '\0';
	ft_strrev((char *)arr->arr);
}

char	*ft_convert_str(t_options *opts, va_list args)
{
	char	*str;
	t_array	arr;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	arr.size = 100;
	arr.arr = malloc(arr.size);
	arr.top = 0;
	if (opts->precision == -1)
		opts->precision = ft_strlen(str);
	ft_store_str(&arr, str, opts);
	return ((char *)arr.arr);
}
