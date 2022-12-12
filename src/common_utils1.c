/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:35:28 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/27 23:32:16 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_get_hexval(char c)
{
	char	*vals;
	int		i;

	vals = "0123456789abcdef";
	if (c >= 'A' && c <= 'F')
		c += 32;
	i = 0;
	while (vals[i] != '\0')
	{
		if (vals[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	ft_hex_atoi(char *str)
{
	int	v;

	if (!str)
		return (0xffffffff);
	v = 0;
	if (*str == ',')
		str++;
	else
		return (0xffffffff);
	str += 2;
	while (*str != '\0' && ft_get_hexval(*str) >= 0)
	{
		v = (v << 4) | ft_get_hexval(*str);
		str++;
	}
	return (v);
}

void	ft_error(void)
{
	ft_putstr_fd("Error!", 2);
	exit(1);
}
