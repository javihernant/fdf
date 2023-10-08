/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:26:04 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/27 20:06:21 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	void	*content;

	result = 0;
	node = 0;
	if (lst == 0 || f == 0)
		return (0);
	while (lst != 0)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			ft_lstclear(&result, del);
			del(content);
			break ;
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
