/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clampint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:54:21 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/07 07:57:35 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_clampint(int input, int min, int max)
{
	if (input <= min)
		return (min);
	if (input >= max)
		return (max);
	return (input);
}
