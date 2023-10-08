/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:46:18 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/21 12:35:39 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;
	int				dif;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	i = 0;
	dif = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			dif = p1[i] - p2[i];
			break ;
		}
		i++;
	}
	return (dif);
}
