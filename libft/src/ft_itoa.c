/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:18:19 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/26 18:55:43 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_digits(int *n, int *b)
{
	int	d;
	int	num;

	d = 1;
	*b = 0;
	if (*n < 0)
	{
		*b = 1;
		d++;
	}
	num = *n;
	while (num / 10 != 0)
	{
		d++;
		num /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	int		b;

	len = ft_count_digits(&n, &b);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	i = len - 1;
	while (i > 0)
	{
		str[i] = '0' + (n % 10);
		if ((n % 10) < 0)
			str[i] = '0' - (n % 10);
		i--;
		n /= 10;
	}
	if (b)
		str[i] = '-';
	else
		str[i] = '0' + (n % 10);
	return (str);
}
