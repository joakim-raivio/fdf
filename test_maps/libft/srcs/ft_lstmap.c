/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:42:56 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 16:51:28 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cur;
	t_list	*head;
	t_list	*temp;

	head = NULL;
	while (lst)
	{
		temp = (f)(lst);
		if (temp == lst)
			temp = ft_lstnew(temp->content, temp->content_size);
		if (!head)
		{
			head = temp;
			cur = temp;
		}
		if (!temp)
		{
			ft_lstdel(&head, ft_memclear);
			return (NULL);
		}
		cur->next = temp;
		lst = lst->next;
		cur = cur->next;
	}
	return (head);
}
