/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:54:05 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/07 11:22:37 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# define SCREEN_W 1920
# define SCREEN_H 1080
# define WINDOW_NAME "FDF"
# define COLOR 0x0000FF00
# define MAX_MAP_X 1000
# define MAX_MAP_Y 1000
# define HEIGHTSCALAR 0.50
# define MIN_HEIGHT -42
# define MAX_HEIGHT 42

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map {
	int			map[MAX_MAP_Y][MAX_MAP_X];
	t_coord		size;
	int			min_z;
	int			max_z;
}				t_map;

void	render(void *mlx, void *window, t_map *map);
void	init_map(char *file, t_map *map);
void	panic(char *message);
int		key_hook(int key_code, void *params);

#endif 
