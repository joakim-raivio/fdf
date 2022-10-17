/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:07:57 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/07 01:18:39 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freearray(char ***result, int j)
{
	while (j >= 0)
		ft_strdel(&(result[0][j--]));
	free(*result);
	return (NULL);
}
