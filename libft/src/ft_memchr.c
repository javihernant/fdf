/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:24:59 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/21 11:31:33 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			i;

	p = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (p[i] == ch)
			break ;
		i++;
	}
	if (p[i] == ch)
		return (&p[i]);
	return (0);
}
