/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalla <oabdalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:17:02 by oabdalla          #+#    #+#             */
/*   Updated: 2021/12/06 15:45:34 by oabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	update_map(int dir, char next_move, t_map *map)
{
	if (dir == 0 && next_move != '1' && check_exit(next_move, map))
	{
		map->map[map->pos_player_y][map->pos_player_x] = '0';
		map->map[map->pos_player_y - 1][map->pos_player_x] = 'P';
		map->pos_player_y--;
	}
	else if (dir == 1 && next_move != '1' && check_exit(next_move, map))
	{
		map->map[map->pos_player_y][map->pos_player_x] = '0';
		map->map[map->pos_player_y][map->pos_player_x - 1] = 'P';
		map->pos_player_x--;
	}
	else if (dir == 2 && next_move != '1' && check_exit(next_move, map))
	{
		map->map[map->pos_player_y][map->pos_player_x] = '0';
		map->map[map->pos_player_y + 1][map->pos_player_x] = 'P';
		map->pos_player_y++;
	}
	else if (dir == 3 && next_move != '1' && check_exit(next_move, map))
	{
		map->map[map->pos_player_y][map->pos_player_x] = '0';
		map->map[map->pos_player_y][map->pos_player_x + 1] = 'P';
		map->pos_player_x++;
	}
}

void	render_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < (map->width) / 64)
	{
		y = 0;
		while (y < (map->height) / 64)
		{
			draw_to_window(map, x, y);
			y++;
		}
		x++;
	}
}
