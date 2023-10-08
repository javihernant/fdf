/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:44:47 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/21 16:07:21 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <sys/errno.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*buf;

	len = ft_strlen(s1);
	buf = malloc(len + 1);
	if (!buf)
	{
		errno = ENOMEM;
		return (0);
	}
	ft_strlcpy(buf, s1, len + 1);
	return (buf);
}
