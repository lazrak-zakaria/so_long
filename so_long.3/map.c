/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:31:14 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/13 13:38:02 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map(char **av, t_map *map_s)
{
	read_map(av, map_s);
	if (!check_wall(map_s))
	{
		ft_putstr("Error", 2);
		ft_free_and_print(map_s->map, 1, "the map must be surrounded by wall");
	}
	if (!(map_s->exit == 1 && map_s->player == 1 && map_s->collectibles > 0))
	{
		ft_putstr("Error", 2);
		ft_free_and_print(map_s->map, 1, "number of E or C or P is not valid");
	}
	if (!ft_check_path(map_s))
	{
		ft_putstr("Error\nThe map doesn't have valid path!! ~_~", 2);
		ft_free_and_print(map_s->map, 1, "");
	}
}

void	ft_putstr(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	ft_putchar('\n', fd);
}

void	read_map(char **av, t_map *map_s)
{
	char	*mem;

	mem = ft_read_map(av);
	map_s->map = ft_split(mem, '\n');
	if (!map_s->map)
	{
		perror("Error");
		free (mem);
		ft_mem_free(map_s->map);
		exit(EXIT_FAILURE);
	}
	free(mem);
	fill_map_struct(map_s->map, map_s);
	if (map_s->character != (ft_strlen(map_s->map[0]) * map_s->line))
		ft_free_and_print(map_s->map, 1, "Error\nthe map must be rectancular");
	if (map_s->error)
		ft_free_and_print(map_s->map, 1, "Error\nwrong character on the map");
}

void	fill_map_struct(char **mem, t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (mem[++i])
	{
		j = -1;
		while (mem[i][++j])
		{
			if (mem[i][j] == 'C')
				map->collectibles++;
			else if (mem[i][j] == 'E')
				map->exit++;
			else if (mem[i][j] == 'P')
			{
				map->player++;
				map->i = i;
				map->j = j;
			}
			else if ((mem[i][j] != '0') && (mem[i][j] != '1'))
				map->error++;
			map->character++;
		}
		map->line++;
	}
}

int	check_wall(t_map *map_s)
{
	int	i;
	int	l;

	l = map_s->line - 1;
	i = 0;
	while (map_s->map[0][i] && map_s->map[l][i])
	{
		if (map_s->map[0][i] != '1' || map_s->map[l][i] != '1')
			return (0);
		++i;
	}
	l = ft_strlen(map_s->map[0]) - 1;
	i = 0;
	while (i < map_s->line)
	{
		if (map_s->map[i][0] != '1' || map_s->map[i][l] != '1')
			return (0);
		++i;
	}
	return (1);
}
