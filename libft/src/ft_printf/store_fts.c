/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:30:12 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/28 14:03:57 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Appends 0's if required for precision
 */
void	ft_store_precision(t_array *arr, t_options *opts)
{
	while (opts->precision > 0)
	{
		ft_arr_handle_outofbounds_depr(arr);
		((char *) arr->arr)[arr->top] = '0';
		opts->precision -= 1;
		opts->width -= 1;
		(arr->top)++;
	}
}

/*
 * Append the same character to the string until width is 0
 */
void	ft_store_width(t_array *arr, int is_neg, t_options *opts)
{
	char	c;

	c = ' ';
	if ((opts->flags & ZER_F) != 0)
	{
		c = '0';
		if (((opts->flags & PLS_F) != 0) || ((opts->flags & SPC_F) != 0)
			|| is_neg)
			opts->width -= 1;
		else if ((opts->flags & HSH_F) != 0)
			opts->width -= 2;
	}
	while (opts->width > 0)
	{
		ft_arr_handle_outofbounds_depr(arr);
		((char *) arr->arr)[arr->top] = c;
		opts->width -= 1;
		(arr->top)++;
	}
}

static void	ft_get_signs(int is_neg, char *sig, t_options *opts)
{
	sig[0] = '\0';
	sig[1] = '\0';
	sig[2] = '\0';
	if (is_neg)
		sig[0] = '-';
	else if ((opts->flags & SPC_F) != 0)
		sig[0] = ' ';
	else if ((opts->flags & PLS_F) != 0)
		sig[0] = '+';
	else if ((opts->flags & HSH_F) != 0)
	{
		sig[0] = 'x';
		if (opts->specifier == 'X')
			sig[0] = 'X';
		sig[1] = '0';
	}
}

void	ft_store_sign(t_array *arr, int is_neg, t_options *opts)
{
	char	sig[3];	
	int		i;

	i = 0;
	ft_get_signs(is_neg, sig, opts);
	while (sig[i] != '\0')
	{
		ft_arr_handle_outofbounds_depr(arr);
		((char *)arr->arr)[arr->top] = sig[i++];
		(arr->top)++;
		opts->width -= 1;
	}
}
