/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalla <oabdalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:26:02 by oabdalla          #+#    #+#             */
/*   Updated: 2021/12/06 15:24:10 by oabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		img_width;
	int		img_height;
	t_mlx	mlx;
	t_data	grass;
	t_data	wall;
	t_data	player;
	t_data	collectable;
	t_data	exit;
	int		num_collectable;
	int		pos_player_x;
	int		pos_player_y;
	int		moves;
}	t_map;

int		exit_program(t_map *map);
void	render_map(t_map *map);
void	update_map(int dir, char next_move, t_map *map);
void	free_map(t_map *map);
void	draw_to_window(t_map *map, int x, int y);
void	init_images(t_map *map);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

int		check_exit(char move, t_map *map);
char	return_next_move(int dir, t_map *map);
void	move_player(int dir, t_map *map);
int		move(int keycode, t_map *map);

void	parse_map(int ac, char *filepath, t_map *map);
int		count_lines(char *filepath);
void	read_map(t_map *map, int lines, char *filepath);

int		check_map_valid(t_map *map);
int		check_strlen(t_map *map, int last);
int		check_top_bottom(t_map *map, int last);
int		check_sides(t_map *map, int last, int lastchar);
int		check_items(t_map *map, int lastchar, int exit, int player);

#endif