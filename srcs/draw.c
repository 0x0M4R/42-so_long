/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalla <oabdalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:15:02 by oabdalla          #+#    #+#             */
/*   Updated: 2021/12/06 15:44:38 by oabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_images(t_map *map)
{
	char	*grass_path;
	char	*wall_path;
	char	*player_path;
	char	*collectable_path;
	char	*exit_path;

	grass_path = "xpms/grass64x64.xpm";
	wall_path = "xpms/wall64x64.xpm";
	player_path = "xpms/player64x64.xpm";
	collectable_path = "xpms/collectable64x64.xpm";
	exit_path = "xpms/exit64x64.xpm";
	map->grass.img = mlx_xpm_file_to_image
		(map->mlx.mlx, grass_path, &map->img_width, &map->img_height);
	map->wall.img = mlx_xpm_file_to_image
		(map->mlx.mlx, wall_path, &map->img_width, &map->img_height);
	map->player.img = mlx_xpm_file_to_image
		(map->mlx.mlx, player_path, &map->img_width, &map->img_height);
	map->collectable.img = mlx_xpm_file_to_image
		(map->mlx.mlx, collectable_path, &map->img_width, &map->img_height);
	map->exit.img = mlx_xpm_file_to_image
		(map->mlx.mlx, exit_path, &map->img_width, &map->img_height);
}

void	draw_to_window(t_map *map, int x, int y)
{
	if (map->map[y][x] == '0')
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->grass.img, x * 64, y * 64);
	if (map->map[y][x] == '1')
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->wall.img, x * 64, y * 64);
	if (map->map[y][x] == 'C')
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->collectable.img, x * 64, y * 64);
	if (map->map[y][x] == 'E')
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->exit.img, x * 64, y * 64);
	if (map->map[y][x] == 'P')
	{
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->player.img, x * 64, y * 64);
		map->pos_player_y = y;
		map->pos_player_x = x;
	}
}
