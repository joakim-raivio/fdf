/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:16:26 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/07 10:26:03 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countwords(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	if (s[i])
		count++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				count++;
			continue ;
		}
		i++;
	}
	return (count);
}
