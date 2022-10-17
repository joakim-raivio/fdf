/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:17:22 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 14:02:07 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		if (!src[i])
		{
			while (len > i)
				dst[i++] = 0;
			return (dst);
		}
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
