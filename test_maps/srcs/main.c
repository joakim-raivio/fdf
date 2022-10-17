/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:54:20 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/17 10:35:00 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_frame *frame)
{
	frame->mlx = mlx_init();
	if (!(frame->mlx))
		panic("MLX initilization failed.");
	frame->window = mlx_new_window(frame->mlx, SCREEN_W, SCREEN_H, WINDOW_NAME);
	if (!(frame->window))
		panic("MLX window initialization failed.");
}

int	main(int argc, char **argv)
{
	t_frame	frame;

	if (argc != 2)
	{
		ft_putendl("Usage: fdf path/to/map.fdf");
		return (1);
	}
	init_map(*(argv + 1), &(frame.map));
	init_fdf(&frame);
	render(frame.mlx, frame.window, &(frame.map), military);
	mlx_key_hook(frame.window, key_hook, &frame);
	mlx_loop(frame.mlx);
	return (0);
}
