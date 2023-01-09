/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:30:44 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/09 12:30:46 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
up right down left
dx[] = {-1, 0, 1, 0};
dy[] = {0, 1, 0, -1};
*/

void	ft_direction(int *dx, int *dy)
{
	dx[0] = -1;
	dx[1] = 0;
	dx[2] = 1;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 1;
	dy[2] = 0;
	dy[3] = -1;
}

int	ft_is_valid(t_map_path *map_path, int r, int c)
{
	if (map_path->map[r][c] == '1' || map_path->map[r][c] == 'Z')
		return (0);
	if (map_path->map[r][c] == 'E' && map_path->collectibles)
	{
		map_path->exit_ok = 1;
		return (0);
	}
	if (map_path->map[r][c] == 'E' && !map_path->collectibles)
		map_path->exit_ok = 1;
	else if (map_path->map[r][c] == 'C')
		map_path->collectibles--;
	return (1);
}

int	ft_search_path(t_map_path *map_path, int i, int j)
{
	int	r;
	int	c;
	int	index;
	int	answer;

	if (!map_path->collectibles && map_path->exit_ok)
		return (1);
	index = -1;
	answer = 0;
	while (++index < 4)
	{
		r = i + map_path->dx[index];
		c = j + map_path->dy[index];
		if (!ft_is_valid(map_path, r, c))
			continue ;
		map_path->map[r][c] = 'Z';
		answer = ft_search_path(map_path, r, c);
	}
	return (answer);
}

void	ft_initialise_map_path(t_map_path *map_path, t_map *map_s)
{
	int	i;

	map_path->map = malloc(sizeof(char *) * (map_s->line + 1));
	if (!map_path->map)
	{
		perror("ERROR:");
		ft_free_and_print(map_s->map, 1, "");
	}
	i = -1;
	map_path->collectibles = map_s->collectibles;
	map_path->exit_ok = 0;
	while (map_s->map[++i])
	{
		map_path->map[i] = ft_strdup(map_s->map[i]);
		if (!map_path->map[i])
		{
			perror("ERROR:");
			ft_mem_free(map_path->map);
			ft_free_and_print(map_s->map, 1, "");
		}
	}
	map_path->map[i] = NULL;
}

int	ft_check_path(t_map *map_s)
{
	t_map_path	map_path;
	int			answer;

	ft_initialise_map_path(&map_path, map_s);
	ft_direction(map_path.dx, map_path.dy);
	map_path.map[map_s->i][map_s->j] = 'Z';
	answer = ft_search_path(&map_path, map_s->i, map_s->j);
	ft_mem_free(map_path.map);
	return (answer);
}
