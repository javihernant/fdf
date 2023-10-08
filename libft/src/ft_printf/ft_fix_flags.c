/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:42:39 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/07 21:08:09 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Ignore flags depending on the flags set
 */
static void	ft_update_flags(t_options *opts)
{
	unsigned char	*flags;

	flags = &opts->flags;
	if ((*flags & MIN_F) != 0)
		*flags &= ~ZER_F;
	if ((*flags & PLS_F) != 0)
		*flags &= ~SPC_F;
	if ((*flags & ZER_F) != 0 && (opts->precision != -1))
		*flags &= ~ZER_F;
}

/*
 * Ignore flags depending on the conversion specifier
 */
static void	ft_update_flags_spec(t_options *opts)
{
	char			sp;
	unsigned char	*flags;

	flags = &opts->flags;
	sp = opts->specifier;
	if (sp == 'u' || sp == 'x' || sp == 'X')
	{
		*flags &= ~PLS_F;
		*flags &= ~SPC_F;
	}
	if (!(sp == 'x' || sp == 'X' || sp == 'p'))
		*flags &= ~HSH_F;
	if (sp == 's')
	{
		*flags &= ~ZER_F;
		*flags &= ~PLS_F;
		*flags &= ~SPC_F;
		*flags &= ~HSH_F;
	}
	if (sp == 'p')
		*flags |= HSH_F;
}

void	ft_fix_flags(t_options *opts)
{
	ft_update_flags(opts);
	ft_update_flags_spec(opts);
}
