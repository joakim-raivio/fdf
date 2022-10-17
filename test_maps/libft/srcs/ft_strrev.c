/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:41:30 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/29 13:23:46 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char **input)
{
	size_t		len;
	size_t		i;
	char		temp;

	len = ft_strlen(*input) - 1;
	i = 0;
	while (i < len)
	{
		temp = input[0][i];
		input[0][i++] = input[0][len];
		input[0][len--] = temp;
	}
	return (*input);
}
