/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:53:13 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/24 12:30:59 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *) s;
	while (*p != '\0')
	{
		if (*p == (unsigned char) c)
			return (p);
		p++;
	}
	if (*p == (unsigned char) c)
		return (p);
	return (0);
}
