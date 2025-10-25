/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:28:41 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/15 13:59:01 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*temp;

	temp = NULL;
	dest = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, temp);
		lst = lst->next;
	}
	return (dest);
}
