/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalla <oabdalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:17:27 by oabdalla          #+#    #+#             */
/*   Updated: 2021/12/09 10:03:52 by oabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	read_map(t_map *map, int lines, char *filepath)
{
	int	f;
	int	i;

	map->map = 0;
	map->map = malloc(sizeof(char *) * (lines + 1));
	map->map[lines] = 0;
	i = 0;
	while (i < lines)
	{
		map->map[i] = 0;
		i++;
	}
	i = 0;
	f = open(filepath, O_RDONLY);
	while (i < lines)
	{
		map->map[i] = get_next_line(f);
		i++;
	}
	close(f);
}

int	count_lines(char *filepath)
{
	int		f;
	int		lines;
	int		r;
	char	buff[1];

	f = open(filepath, O_RDONLY);
	if (f < 0)
	{
		write(1, "Error\nFile could not be opened.\n", 33);
		exit(0);
	}
	lines = 0;
	r = read(f, buff, 1);
	if (r < 1)
	{
		write(1, "Error\nFile could not be read.\n", 31);
		exit(0);
	}
	while (r > 0)
	{
		if (*buff == '\n')
			lines++;
		r = read(f, buff, 1);
	}
	return (lines + 1);
}

int	check_ber(char *str)
{
	int	l;

	l = ft_strlen(str);
	if (str[l - 1] != 'r' || str[l - 2] != 'e'
		|| str[l - 3] != 'b' || str[l - 4] != '.')
		return (0);
	return (1);
}

void	parse_map(int ac, char *filepath, t_map *map)
{
	int	lines;

	if (ac != 2)
	{
		write(1, "Error\nWrong number of arguments.\n", 34);
		exit(0);
	}
	if (!check_ber(filepath))
	{
		write(1, "Error\nNot .ber file.\n", 22);
		exit(0);
	}
	lines = count_lines(filepath);
	read_map(map, lines, filepath);
	map->num_collectable = 0;
	map->moves = 0;
	map->height = lines * 64;
	if (!check_map_valid(map))
	{
		write(1, "Error\nInvalid map.\n", 20);
		free_map(map);
		exit(0);
	}
	map->width = (ft_strlen(map->map[0]) - 1) * 64;
}
