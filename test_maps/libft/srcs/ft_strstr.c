/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:39:42 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/08 15:05:16 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i1])
	{
		if (haystack[i1] == needle[i2])
		{
			while (haystack[i1] == needle[i2])
			{
				i1++;
				i2++;
				if (!needle[i2])
					return ((char *)(haystack + (i1 - i2)));
			}
			i1 -= i2;
			i2 = 0;
		}
		i1++;
	}
	return (NULL);
}
