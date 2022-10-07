/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:54:20 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/07 11:20:53 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	init_fdf(void **mlx, void **window)
{
	*mlx = mlx_init();
	if (!*mlx)
		exit (1);
	*window = mlx_new_window(*mlx, SCREEN_W, SCREEN_H, WINDOW_NAME);
	if (!*window)
		exit (1);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_map	map;

	if (argc != 2)
		return (1);
	init_map(*(argv + 1), &map);
	init_fdf(&mlx, &window);
	render(mlx, window, &map);
	mlx_key_hook(window, key_hook, NULL);
	mlx_loop(mlx);
	return (0);
}
