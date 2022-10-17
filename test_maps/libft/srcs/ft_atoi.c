/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:07:25 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 17:01:25 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	while (ft_iswhitespace(*str))
		str++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] - 44) * -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - 48);
	return (result * sign);
}
