/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:48:14 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/07 21:58:19 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_val2str(t_options *opts, va_list args, size_t *len)
{
	char	*str;
	char	sp;

	*len = 0;
	sp = opts->specifier;
	str = 0;
	if (sp == 'd' || sp == 'i')
		str = ft_convert_dec(opts, args);
	else if (sp == 'x' || sp == 'X' || sp == 'u')
		str = ft_convert_usig(opts, args);
	else if (sp == 'p')
		str = ft_convert_p(opts, args);
	else if (sp == 's')
		str = ft_convert_str(opts, args);
	else if (sp == 'c' || sp == '%')
		str = ft_convert_c(opts, args, len);
	if (str)
		*len = ft_strlen(str);
	return (str);
}

/*
 * Prints the converted value and returns how many chars have been printed.
 */
size_t	ft_print_value(t_options *opts, va_list args)
{
	size_t	len;
	char	*str;

	str = ft_val2str(opts, args, &len);
	if (str)
		ft_putstr_fd(str, 1);
	if ((opts->flags & MIN_F) != 0)
	{
		while (opts->width > 0)
		{
			ft_putchar_fd(' ', 1);
			len += 1;
			opts->width -= 1;
		}
	}
	free(str);
	return (len);
}
