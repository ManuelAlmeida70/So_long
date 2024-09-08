/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:34:28 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/18 08:34:37 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	tamlist;
	int	i;

	i = 0;
	tamlist = ft_lstsize(lst);
	while (i < tamlist - 1)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}
