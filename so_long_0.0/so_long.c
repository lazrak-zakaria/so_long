#include "so_long.h"


int main(int ac, char **av, char **env)
{
	int		l;
	char	*mem;
	t_map	map;

	if (ac != 2)
	{ printf("error: argument\n"); exit(0);}
	l = ft_strlen(av[1]) - 4;
	if (strncmp(av[1] + l, ".ber", 4))
	{
		printf("error: map .ber\n");
		return 0;
	}
	ft_memset(&map, 0, sizeof(map));
	ft_map(av, &map);
	game(&map, ft_strlen(map.map[0]), map.map);

	return 0;
}