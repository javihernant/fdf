/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:53:57 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/06 22:22:48 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_c(t_options *opts, va_list args, size_t *len)
{
	int		c;

	c = '%';
	*len = 0;
	if (opts->specifier == 'c')
		c = va_arg(args, int);
	opts->width -= 1;
	if ((opts->flags & MIN_F) == 0)
	{
		while (opts->width > 0)
		{
			ft_putchar_fd(' ', 1);
			opts->width -= 1;
			*len += 1;
		}
	}
	ft_putchar_fd(c, 1);
	*len += 1;
	return (0);
}
