/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:34:43 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/05 19:03:42 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed;

	printed = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			printed += ft_handle_conversion(&str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			printed++;
			str++;
		}
	}
	va_end(args);
	return (printed);
}
