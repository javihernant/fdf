/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:01:32 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/07 21:07:15 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_handle_conversion(const char **str, va_list args)
{
	t_options	opts;	
	size_t		printed;

	ft_init_opts(&opts);
	(*str)++;
	ft_process_flags(str, &opts);
	ft_process_width(str, &opts);
	ft_process_precision(str, &opts);
	ft_process_spec(str, &opts);
	ft_fix_flags(&opts);
	printed = ft_print_value(&opts, args);
	return (printed);
}
