/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopref.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:37:06 by jraivio           #+#    #+#             */
/*   Updated: 2022/01/24 17:14:30 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpopref(t_list *head, t_list **del)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	next = head;
	while (next != *del)
	{
		prev = next;
		next = next->next;
	}
	if (prev)
		prev->next = next->next;
	ft_lstdelone(del, ft_memclear);
}
