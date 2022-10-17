/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:20:28 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 14:01:37 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n-- > 0)
	{
		s1 += 1;
		s2 += 1;
	}
	if (n > 0)
		return ((int)((unsigned char)*s1 - (unsigned char)*s2));
	return (0);
}
