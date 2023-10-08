/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:38:46 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/11 15:59:32 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sorted(int *arr, size_t n)
{
	size_t	i;
	int		last;

	if (n <= 1)
		return (1);
	last = arr[0];
	i = 1;
	while (i < n)
	{
		if (arr[i] < last)
			return (0);
		i++;
	}
	return (1);
}

void	ft_int_sort(int *arr, size_t n)
{
	int		tmp;
	size_t	i;

	if (!arr)
		return ;
	while (!ft_is_sorted(arr, n))
	{
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
	}
}
