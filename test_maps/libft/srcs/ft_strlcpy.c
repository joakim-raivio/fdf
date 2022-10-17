/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:29:54 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 17:38:30 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	srclen;

	size = 0;
	srclen = (size_t)ft_strlen(src);
	while (*src && dstsize > size + 1)
		dst[size++] = *src++;
	if (dstsize > 0)
		dst[size] = '\0';
	if (dstsize <= srclen)
		return (srclen);
	return (size);
}
