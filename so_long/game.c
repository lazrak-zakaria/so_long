#include "so_long.h"

// mlx_loop_hook(data.mlx_ptr, handle_no_event, &data)
void	game2(char **mem, t_window *window);


int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	
	return (0);
}
int	handle_des(t_window *window)
{
	ft_mem_free(window->map);
	mlx_destroy_window(window->mlx, window->mlx_win);
	exit(0);
}
int	handle_keypress(int keysym, t_window *window)
{
	
	if (keysym == 53)
	{
		ft_mem_free(window->map);
		mlx_destroy_window(window->mlx, window->mlx_win);
		exit(0);
	}
	else if (keysym == 126)
		move(window, "up");
	else if (keysym == 124)
		move(window, "right");
	else if (keysym == 125)
		move(window, "down");
	else if (keysym == 123)
		move(window, "left");
	else 
	return 0;

	//printf("\ntotal_move = %d  Keypress: %d\n", window->total_move, keysym);
	return (0);
}

void	game(t_map *map, int ll, char **mem)
{
	t_window window;

	ft_memset(&window, 0, sizeof(window));
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 50 * ll , 50 * map->line, "GAME");

	game2(mem, &window);
	window.i = map->i;
	window.j = map->j;
	window.c = map->collectibles;
	window.map = map->map;
	//mlx_loop_hook(window.mlx, handle_no_event, &window);
	mlx_hook(window.mlx_win, 2, 0, &handle_keypress, &window);
	mlx_hook(window.mlx_win, 17, 0, &handle_des, &window);
	mlx_loop(window.mlx);
}


void	game2(char **mem, t_window *window)
{
	int	i;
	int	j;
	int w;
	int h;

	window->collectible = mlx_xpm_file_to_image(window->mlx, "./col.xpm", &w, &h);
	window->exit = mlx_xpm_file_to_image(window->mlx, "./img3.xpm", &w, &h);
	window->player = mlx_xpm_file_to_image(window->mlx, "./img5.xpm", &w, &h);
	window->wall = mlx_xpm_file_to_image(window->mlx, "./wall.xpm", &w, &h);
	window->fre = mlx_xpm_file_to_image(window->mlx, "./free_space.xpm", &w, &h);
	i = -1;
	while(mem[++i])
	{
		j = -1;
		printf("%s\n", mem[i]);
		while (mem[i][++j])
		{
			if (mem[i][j] == 'P')
				 mlx_put_image_to_window (window->mlx, window->mlx_win, window->player, j*50, (i*50));
			else if (mem[i][j] == 'C')
				 mlx_put_image_to_window(window->mlx, window->mlx_win, window->collectible, j*50, i*50);
			else if (mem[i][j] == '1')
				 mlx_put_image_to_window(window->mlx, window->mlx_win, window->wall, j*50, i*50);
			else if (mem[i][j] == '0')
				mlx_put_image_to_window(window->mlx, window->mlx_win, window->fre, j*50, i*50);
			else
				mlx_put_image_to_window(window->mlx, window->mlx_win, window->exit, j*50, i*50);
		}
	}
}

void	move(t_window *win, char *s)
{
	int	player_now_x;
	int	player_now_y;

	player_now_x = win->i;
	player_now_y = win->j;
	if (ft_cmp(s, "up", 2))
		win->i--;
	else if (ft_cmp(s, "right", 5))
		win->j++;
	else if (ft_cmp(s, "down", 4))
		win->i++;
	else
		win->j--;
	if (win->map[win->i][win->j] == '1' || (win->map[win->i][win->j] == 'E' && win->c))
	{
		win->i = player_now_x;
		win->j = player_now_y;
		return ;
	}
	ft_putnbr(++win->total_move);
	if (win->map[win->i][win->j] == 'E' && !win->c)
	{
		ft_mem_free(win->map);
		ft_putstr("\nWIN");
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}
	if (win->map[win->i][win->j] == 'C')
		win->c--;
	win->map[player_now_x][player_now_y] = '0';
	win->map[win->i][win->j] = 'P';
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->fre, player_now_y * 50, player_now_x * 50);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->fre, win->j * 50, win->i * 50);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->player, win->j * 50, win->i * 50);

}