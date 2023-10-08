/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:22:25 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/05 19:04:15 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_precision(const char **str, t_options *opts)
{
	int	precision;

	if (*(*str) == '.')
	{
		(*str)++;
		precision = ft_atoi(*str);
		if (precision < 0)
		{
			precision = 0;
			(*str)++;
		}
		while (ft_isdigit(*(*str)))
			(*str)++;
		opts->precision = precision;
	}
}
