/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:27:12 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/11 17:51:24 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int key_code, t_frame *frame)
{
	if (key_code == 53)
		exit(0);
	else if (key_code == 18)
		render(frame->mlx, frame->window, &(frame->map), military);
	else if (key_code == 19)
		render(frame->mlx, frame->window, &(frame->map), isometric);
	return (0);
}
