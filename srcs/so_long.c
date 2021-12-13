/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalla <oabdalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:12:32 by oabdalla          #+#    #+#             */
/*   Updated: 2021/12/07 20:02:45 by oabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_program(t_map *map)
{
	free_map(map);
	mlx_destroy_window(map->mlx.mlx, map->mlx.win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	parse_map(ac, av[1], &map);
	map.mlx.mlx = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.mlx, map.width, map.height, "so_long");
	init_images(&map);
	render_map(&map);
	mlx_hook(map.mlx.win, 2, 1L << 0, move, &map);
	mlx_hook(map.mlx.win, 17, 0L, exit_program, &map);
	mlx_loop(map.mlx.mlx);
}
