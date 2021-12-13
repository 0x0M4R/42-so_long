/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalla <oabdalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:19:46 by oabdalla          #+#    #+#             */
/*   Updated: 2021/12/07 18:36:31 by oabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_strlen(t_map *map, int last)
{
	int		i;
	size_t	len;

	len = ft_strlen(map->map[0]);
	i = 0;
	while (i < last)
	{
		if (len != ft_strlen(map->map[i]))
			return (0);
		i++;
	}
	if (len != ft_strlen(map->map[i]) + 1)
		return (0);
	return (1);
}

int	check_top_bottom(t_map *map, int last)
{
	int	i;

	i = 0;
	while (map->map[0][i] != '\n')
	{
		if (map->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map->map[last][i])
	{
		if (map->map[last][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_sides(t_map *map, int last, int lastchar)
{
	int	i;

	i = 1;
	while (i < last)
	{
		if (map->map[i][0] != '1' || map->map[i][lastchar] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_items(t_map *map, int lastchar, int exit, int player)
{
	int	i;
	int	j;

	i = 1;
	while (i < (map->height / 64) - 1)
	{
		j = 1;
		while (j < lastchar)
		{
			if (map->map[i][j] == 'P')
				player++;
			else if (map->map[i][j] == 'C')
				map->num_collectable++;
			else if (map->map[i][j] == 'E')
				exit++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || !map->num_collectable)
		return (0);
	return (1);
}

int	check_map_valid(t_map *map)
{
	int	lastchar;
	int	player;
	int	exit;
	int	last;

	last = (map->height / 64) - 1;
	if (!check_strlen(map, last))
		return (0);
	if (!check_top_bottom(map, last))
		return (0);
	lastchar = ft_strlen(map->map[0]) - 2;
	if (!check_sides(map, last, lastchar))
		return (0);
	map->num_collectable = 0;
	player = 0;
	exit = 0;
	if (!check_items(map, lastchar, exit, player))
		return (0);
	if (last == lastchar)
		return (0);
	return (1);
}
