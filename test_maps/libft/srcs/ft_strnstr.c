/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:39:42 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 13:09:18 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i1] && len > 0)
	{
		if (haystack[i1] == needle[i2])
		{
			while (haystack[i1++] == needle[i2++])
				if (!len--)
					return (NULL);
			else if (!needle[i2])
				return ((char *)(haystack + (i1 - i2)));
			i1 -= i2;
			len += i2;
			i2 = 0;
		}
		i1++;
		len--;
	}
	return (NULL);
}
