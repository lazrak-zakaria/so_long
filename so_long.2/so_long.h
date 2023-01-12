/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:30:01 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/12 15:33:11 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>

# define PX 50

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
	int		i;
	int		j;
}	t_map;

typedef struct s_map_path
{
	char	**map;
	char	exit_ok;
	int		collectibles;
	int		dx[4];
	int		dy[4];
}	t_map_path;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*fre;
	int		c;
	int		total_move;
	int		i;
	int		j;
	char	**map;

	void	*right;
	void	*left;
	void	*down;
}	t_window;

char	**ft_split(char *s, char c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *s, int n, int size);
char	**ft_mem_free(char **a);
char	*get_lines(int fd);

void	read_map(char **av, t_map *map_s);
void	fill_map_struct(char **mem, t_map *map);
void	ft_map(char **av, t_map *map_s);
int		check_wall(t_map *map_s);

int		ft_check_path(t_map *map_s);
char	*ft_strdup(char *s);
int		ft_check_num_of_characters(t_map *map_s);
int		ft_cmp(char *a, char *b, int n);

void	move(t_window *win, char *s);
void	ft_putstr(char *s);

void	ft_free_and_print(char **mem, int status, char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);

void	game(t_map *map, int ll);
void	ft_check_xpm(t_window *win, char **map);
void	game2(char **mem, t_window *window);
void	ft_put_imgs(char **map, t_window *win);
void	ft_put_imgs2(char *map, t_window *win, int i);
void	move(t_window *win, char *s);
void	ft_do_move(t_window *win, int player_now_x, int player_now_y, char *c);
char	ft_target_place(t_window *win, char *s);
void	*ft_img_rotate(t_window *win, char c);

int		check_map_new_line(char *mem);
char	*ft_read_map(char **av);

#endif
