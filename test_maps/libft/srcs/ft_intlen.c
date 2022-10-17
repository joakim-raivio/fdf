/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:02:10 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 13:18:13 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t	result;

	result = 0;
	if (n < 0)
	{
		result++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		result++;
	}
	return (result + 1);
}
