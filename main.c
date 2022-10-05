/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:54:20 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/05 20:11:06 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(void **mlx, void **window)
{
	*mlx = mlx_init();
	if (!*mlx)
		exit (1);
	*window = mlx_new_window(*mlx, SCREEN_W, SCREEN_H, WINDOW_NAME);
	if (!*window)
		exit (1);
}

int		main(void)
{
	void	*mlx;
	void	*window;
//	t_map	*map;

	init_fdf(&mlx, &window);

	//map = read_map()
	render(mlx, window, NULL);
	mlx_loop(mlx);

	return (0);
}
