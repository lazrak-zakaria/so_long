#include "so_long.h"
/*
			//up right down left
int	dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int	is_valid(int x, int y, char **map, int *ok)
{

	if (map[x][y] == 'z' || map[x][y] == '1')
		return 0;
	if (map[x][y] == 'E')
		*ok = 1;
	if (map[x][y] == 'C')
	{
		printf("+++++++++++++\n");
		printf("x = %d y = %d\n", x, y);
		printf("****%c****\n", map[x][y]);
		printf("+++++++++++++\n\n");
		return 3;
	}
	return (1);
}

// can reach exit ?? 
// can collect all ??

int	check_path(char **map, int *c, int i, int j, int *ok)
{
	int	nr;
	int	nc;
	int	k;
	int	ans;
	

	k = 0;
	ans = 0;
	int o = 0;
	while (o < 4)
	{
		nr = i + dx[o];
		nc = j + dy[o];

		int t = is_valid(nr, nc, map, ok);
		if (!t)
		{
			++o;
			continue ;
		}
		if (t == 3)
			--(*c);
		if (!(*c) && *ok)
			return (1);
		printf("__%d__%d__\n\n", nr, nc);
		char ll = map[nr][nc];
		map[nr][nc] = 'z';
		ans = check_path(map, c, nr, nc, ok);
		//map[nr][nc] = ll;
	++o;
	}
	return ans;
}

int main()
{
	char *map[] ={"1111111111111",
				  "1C000C0000101",
				  "11101P0110011",
				  "1C00101010CE1",
				  "1111111111111", NULL
				};
	char **mapp =  malloc(sizeof(char*) * 5);
	for(int i = 0; map[i] != NULL ; ++i)
	{
		mapp[i] = strdup(map[i]);
	}
			int c = 4;
	mapp[2][5]= 'z';
	int ok = 0;
	printf("%d\n",check_path(mapp, &c, 2,5, &ok) );
	return 0;
}
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
	if (map_path->map[r][c] == 'E')
	{
		map_path->map[r][c] = 'Z';
		map_path->exit_ok = 1;
		return (0);
	}
	else if (map_path->map[r][c] == 'C')
		map_path->collectibles--;
	return (1);
}

int	ft_search_path(t_map_path *map_path, int i, int j)
{
	int	r;
	int	c;
	int	index;
	int	valid;
	int	answer;

	index = -1;
	answer = 0;
	while (++index < 4)
	{
		r = i + map_path->dx[index];
		c = j + map_path->dy[index];
		if (!ft_is_valid(map_path, r, c))
			continue;
		if (!map_path->collectibles && map_path->exit_ok)
			return (1);
		map_path->map[r][c] = 'Z';
		answer = ft_search_path(map_path, r, c);
	}
	return (answer);
}

int	ft_check_path(t_map *map_s)
{
	t_map_path	map_path;
	int			answer;

	map_path.map = malloc(sizeof(char *) * (map_s->line + 1));
	//protect;
	int	i = -1;
	map_path.collectibles = map_s->collectibles;
	map_path.exit_ok = 0;
	while (map_s->map[++i])
		map_path.map[i] = ft_strdup(map_s->map[i]);
	map_path.map[i] = NULL;
	 i = -1;
	ft_direction(map_path.dx, map_path.dy);
	//printf("___x = %d  ____y = %d\n", map_s->i, map_s->j);
	map_path.map[map_s->i][map_s->j] = 'Z';
	answer = ft_search_path(&map_path, map_s->i, map_s->j);
	printf("heeeeeeeeee\n");
	ft_mem_free(map_path.map);
	return (answer);
}
