/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:14:16 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/03 20:19:41 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < (len / 2))
	{
		j = len - i - 1;
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
	}
}
