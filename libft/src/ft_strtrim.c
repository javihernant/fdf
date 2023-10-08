/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:43:14 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/24 20:44:17 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	j = ft_strlen(s1);
	while (j > 0 && ft_strrchr(set, s1[j]) != 0)
		j--;
	str = ft_substr(s1, i, j - i + 1);
	if (!str)
		return (0);
	return (str);
}
