/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:36:00 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/18 08:36:16 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*listreturn;
	void	*temp;

	if (!lst || !f || !del)
		return (0);
	element = NULL;
	listreturn = NULL;
	while (lst)
	{
		temp = f(lst->content);
		element = ft_lstnew(temp);
		if (!element)
		{
			del(temp);
			ft_lstclear(&listreturn, del);
			return (listreturn);
		}
		ft_lstadd_back(&listreturn, element);
		lst = lst->next;
	}
	return (listreturn);
}
