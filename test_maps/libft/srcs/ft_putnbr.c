/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:10:33 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 13:49:30 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < -9 || n > 9)
		ft_putnbr(n / 10);
	else if (n >= -9 && n < 0)
	{
		ft_putchar('-');
		ft_putchar((char)(n * -1) + '0');
		return ;
	}
	n %= 10;
	if (n < 0)
		n *= -1;
	ft_putchar((char)n + '0');
}
