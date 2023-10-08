/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:38:11 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/24 10:21:50 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	p = (char *) haystack;
	if (*needle == '\0')
		return (p);
	while (p[i] != '\0' && i < len)
	{
		j = 0;
		while (i + j < len && p[i + j] != '\0'
			&& needle[j] != '\0' && p[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return (&p[i]);
		i++;
	}
	return (0);
}
