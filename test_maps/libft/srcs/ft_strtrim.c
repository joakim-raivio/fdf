/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:43:40 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/29 14:26:02 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	end;
	size_t	start;
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
		i--;
	end = ft_strlen(s) - i - 1;
	if (start >= ft_strlen(s))
		return (ft_strnew(0));
	return (ft_strsub(s, (unsigned int) start,
			(ft_strlen(s) - start - end)));
}
