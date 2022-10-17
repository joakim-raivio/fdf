/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:13:08 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/29 14:24:16 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	int		i;

	new = ft_strnew((size_t)ft_strlen(s));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = (*f)(s[i]);
		i++;
	}
	return (new);
}
