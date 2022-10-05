/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:54:05 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/05 21:04:31 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "libft.h"
#include <mlx.h>
#include <math.h>
# define SCREEN_W 1920
# define SCREEN_H 1080
#define WINDOW_NAME "FDF"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_map {
	int		**lines;
	size_t	line_len;
	size_t	line_count;
}				t_map;

typedef struct	s_coord {
	int	x;
	int	y;
}				t_coord;

void	render(void *mlx, void *window, t_map *map);

#endif 
