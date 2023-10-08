/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:46:03 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/27 18:41:40 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

static void	ft_copyuntil(char *dst, char const *s, char *end)
{
	while (s < end)
	{
		*dst = *s;
		dst++;
		s++;
	}
	*dst = '\0';
}

/* Update s until it is pointing to a char != d. Then, return next delim */
static char	*ft_next_delim(const char **s, char d)
{
	char	*lim;

	while (*(*s) != '\0' && *(*s) == d)
		(*s)++;
	lim = ft_strchr(*s, d);
	if (!lim)
		lim = ft_strchr(*s, '\0');
	return (lim);
}

static int	ft_count_ws(char const *s, char c)
{
	char	*lim;
	int		words;

	words = 0;
	while (*s != '\0')
	{
		lim = ft_next_delim(&s, c);
		if (*s != '\0')
		{
			words++;
		}
		s = lim;
	}
	return (words);
}

static int	ft_has_to_free(char **s, int len)
{
	int	i;

	i = 0;
	if (s[len] == 0)
	{
		while (i < len)
		{
			free(s[i]);
			i++;
		}
		free(s);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	*lim;
	int		i;
	char	**ws;

	i = 0;
	ws = (char **) malloc(sizeof(char *) * (ft_count_ws(s, c) + 1));
	if (!ws)
		return (0);
	while (*s != '\0')
	{
		lim = ft_next_delim(&s, c);
		if (*s != '\0')
		{
			ws[i] = (char *) malloc(lim - s + 1);
			if (ft_has_to_free(ws, i))
				return (0);
			ft_copyuntil(ws[i], s, lim);
			i++;
		}
		s = lim;
	}
	ws[i] = 0;
	return (ws);
}
