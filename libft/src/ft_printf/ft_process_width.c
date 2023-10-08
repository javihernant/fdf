/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:14:16 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/05 19:04:30 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_width(const char **str, t_options *opts)
{
	int	width;

	width = ft_atoi(*str);
	while (ft_isdigit(*(*str)))
		(*str)++;
	opts->width = width;
}
