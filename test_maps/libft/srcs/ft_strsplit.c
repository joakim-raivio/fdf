/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:49 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/14 13:51:13 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (c == '\0')
		return (NULL);
	result = ft_memalloc(sizeof(char **) * (size_t)(ft_countwords(s, c) + 1));
	if (!result || sizeof(result) == 0)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = ft_get_delim_str(s, c, i);
			if (!result[j])
				return (ft_freearray(&result, j - 1));
			i += ft_strlen(result[j++]);
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
