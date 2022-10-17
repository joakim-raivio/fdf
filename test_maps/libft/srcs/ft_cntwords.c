/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:16:26 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/29 14:20:35 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cntwords(const char *s, char c)
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
			count++;
			while (s[i] != c)
				i++;
		}
		i++;
	}
	return (count);
}
