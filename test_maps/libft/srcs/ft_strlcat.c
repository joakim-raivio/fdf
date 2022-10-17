/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:21 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 16:49:06 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;

	dstlen = (size_t)ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + (size_t)ft_strlen(src));
	ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return (dstlen + (size_t)ft_strlen(src));
}
