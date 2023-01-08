#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <mlx.h>

typedef	struct s_player
{
	int	i;
	int	j;
} t_player;

typedef struct s_map
{
	int		walls;
	int		collectibles;
	int		free_space;
	int		exit;
	int		player;
	int		error;
	int		line;
	int		character;
	char	**map;
	
	
	int i;
	int j;
} t_map;

typedef struct s_map_path
{
	char	**map;
	char	exit_ok;
	int		collectibles;
	int		dx[4];
	int		dy[4];
} t_map_path;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int 	i;
	int j;
	char	**map;

} t_window;

char	*get_lines(int fd);
char	**ft_split(char *s, char c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *s, int n, int size);
void	game(t_map *map, int ll, char **mem);
char	**ft_mem_free(char **a);

void	read_map(char **av, t_map *map_s);
void	fill_map_struct(char **mem, t_map *map);
int	check_wall(t_map *map_s);
void	ft_map(char **av, t_map *map_s);

int	ft_check_path(t_map *map_s);
char	*ft_strdup(char *s);
int	ft_check_num_of_characters(t_map *map_s);
