#include "so_long.h"

void	ft_map(char **av, t_map *map_s)
{ 
	read_map(av, map_s); 
	if (!check_wall(map_s))   
		ft_free_and_print(map_s->map, 1, "THE MAP SHOULD BE SUROUNDED BY WALL");
	if (!ft_check_num_of_characters(map_s))
		ft_free_and_print(map_s->map, 1, "The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid");
	if (!ft_check_path(map_s))
		ft_free_and_print(map_s->map, 1, "NO VALID PATH ON THE MAP!! ~_~");
}

void	ft_free_and_print(char **mem, int status, char *s)
{
	ft_mem_free(mem);
	if (*s)
		ft_putstr(s);
	exit(status);
}
void	read_map(char **av, t_map *map_s)
{
	char	*mem;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	mem = get_lines(fd);
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
		ft_free_and_print(map_s->map, 1, "THE MAP SHOULD BE RECTANGULAR");
	if (map_s->error)
		ft_free_and_print(map_s->map, 1, "THE MAP SHOULD CONTAIN ONLY : P, E, C, 0, 1 CHARACTERS");
}

void	fill_map_struct(char **mem, t_map *map)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(mem[0]);
	while (mem[++i])
	{
		int j = -1;
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
	int	j;
	int	l;

	l = map_s->line - 1;
	i = 0;
	while (map_s->map[0][i] && map_s->map[l][i])
	{
		if(map_s->map[0][i] != '1' || map_s->map[l][i] != '1')
			return (0);
		++i;
	}
	l = ft_strlen(map_s->map[0]) - 1;
	i = 0;
	while (i < map_s->line)
	{
		if(map_s->map[i][0] != '1' || map_s->map[i][l] != '1')
			return (0);
		++i;
	}
	return (1);
}

int	ft_check_num_of_characters(t_map *map_s)
{
	return (map_s->exit == 1 &&  map_s->player == 1 && map_s->collectibles > 0);
}

/*
up right down left
dx[] = {-1, 0, 1, 0};
dy[] = {0, 1, 0, -1};
*/
