/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:55:40 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/24 16:05:36 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (*s1 != '\0')
	{
		str[i++] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
