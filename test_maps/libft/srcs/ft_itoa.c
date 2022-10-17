/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:54:51 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 13:05:34 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*buf;
	int		i;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	buf = ft_strnew(ft_intlen(n));
	if (!buf)
		return (NULL);
	i = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (n > 9)
	{
		buf[i++] = '0' + (char)(n % 10);
		n /= 10;
	}
	buf[i] = '0' + (char)n;
	if (sign)
		buf[i + 1] = '-';
	return (ft_strrev(&buf));
}
