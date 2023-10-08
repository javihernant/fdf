/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:34:15 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/05 19:03:56 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_store_flag(char c, t_options *opts)
{
	if (c == '0')
		opts->flags |= ZER_F;
	else if (c == '-')
		opts->flags |= MIN_F;
	else if (c == '#')
		opts->flags |= HSH_F;
	else if (c == ' ')
		opts->flags |= SPC_F;
	else if (c == '+')
		opts->flags |= PLS_F;
}

static int	ft_is_flag(char c)
{
	return (c == '0' || c == '-' || c == '#' || c == ' ' || c == '+');
}

void	ft_process_flags(const char **str, t_options *opts)
{
	char	c;

	c = *(*str);
	while (ft_is_flag(c))
	{
		ft_store_flag(c, opts);
		(*str)++;
		c = *(*str);
	}
}
