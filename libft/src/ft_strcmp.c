/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:15:25 by jahernan          #+#    #+#             */
/*   Updated: 2022/11/05 17:15:47 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checklen(char *s1, char *s2)
{
	int	res;

	res = 0;
	if (*s1 != '\0' && *s2 == '\0')
	{
		res = 1;
	}
	if (*s2 != '\0' && *s1 == '\0')
	{
		res = -1;
	}
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	res;

	res = 0;
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
		{
			res = 1;
			break ;
		}
		if (*s1 < *s2)
		{
			res = -1;
			break ;
		}
		s1 += 1;
		s2 += 1;
	}
	if (res == 0)
	{
		res = ft_checklen(s1, s2);
	}
	return (res);
}
