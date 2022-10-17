/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:50:32 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/29 14:25:50 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	new = ft_strnew(len);
	if (!new)
		return (NULL);
	i = 0;
	while (len--)
		new[i++] = s[start++];
	return (new);
}
