/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:28:35 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/18 08:28:44 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!*lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free(*lst);
	*lst = 0;
}
