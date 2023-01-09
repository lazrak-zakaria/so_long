/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:30:53 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/09 14:41:13 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function needs to exist, but it is useless for the moment */
int	handle_no_event(void *data)
{
	(void)data;
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
	else if (keysym == 126 || keysym == 13)
		move(window, "up");
	else if (keysym == 124 || keysym == 2)
		move(window, "right");
	else if (keysym == 125 || keysym == 1)
		move(window, "down");
	else if (keysym == 123 || keysym == 0)
		move(window, "left");
	return (0);
}

void	game(t_map *map, int ll)
{
	t_window	window;

	ft_memset(&window, 0, sizeof(window));
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, PX * ll,
			PX * map->line, "GAME");
	game2(map->map, &window);
	window.i = map->i;
	window.j = map->j;
	window.c = map->collectibles;
	window.map = map->map;
	mlx_loop_hook(window.mlx, handle_no_event, &window);
	mlx_hook(window.mlx_win, 2, 0, &handle_keypress, &window);
	mlx_hook(window.mlx_win, 17, 0, &handle_des, &window);
	mlx_loop(window.mlx);
}

void	game2(char **map, t_window *win)
{
	int	w;
	int	h;

	win->collectible = mlx_xpm_file_to_image(win->mlx, "./col.xpm", &w, &h);
	win->exit = mlx_xpm_file_to_image(win->mlx, "./exit.xpm", &w, &h);
	win->player = mlx_xpm_file_to_image(win->mlx, "./player.xpm", &w, &h);
	win->wall = mlx_xpm_file_to_image(win->mlx, "./wall.xpm", &w, &h);
	win->fre = mlx_xpm_file_to_image(win->mlx, "./empty.xpm", &w, &h);
	ft_check_xpm(win, map);
	ft_put_imgs(map, win);
}
