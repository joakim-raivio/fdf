/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:32:29 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/06 22:18:09 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoind(const char *s1, const char *s2, const char c)
{
	char	*new;

	new = ft_strnew((size_t)(ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	if (ft_strlen(new) > 0)
		new[ft_strlen(new)] = c;
	ft_strcat(new, s2);
	return (new);
}
