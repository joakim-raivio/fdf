/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:10:33 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/25 13:49:46 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -9 || n > 9)
		ft_putnbr_fd(n / 10, fd);
	else if (n >= -9 && n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((char)(n * -1) + '0', fd);
		return ;
	}
	n %= 10;
	if (n < 0)
		n *= -1;
	ft_putchar_fd((char)n + '0', fd);
}
