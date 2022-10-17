/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_delim_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:23:13 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/29 14:20:52 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_delim_str(const char *s, char c, int i)
{
	char	*new;
	int		len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	i -= len;
	len++;
	new = ft_strnew((size_t)len + 1);
	if (!new)
		return (NULL);
	len = 0;
	while (s[i] != '\0' && s[i] != c)
		new[len++] = s[i++];
	return (new);
}
