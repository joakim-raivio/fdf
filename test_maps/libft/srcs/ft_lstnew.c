/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:29:47 by jraivio           #+#    #+#             */
/*   Updated: 2021/12/07 19:23:31 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	new->content = ft_memalloc(content_size);
	if (!(new->content))
	{
		free(new);
		return (NULL);
	}
	else
	{
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	return (new);
}
