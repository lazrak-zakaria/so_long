/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:30:53 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/15 13:43:54 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_des(t_window *window)
{
	ft_mem_free(window->map);
	mlx_destroy_window(window->mlx, window->mlx_win);
	exit(0);
}

int	handle_keypress(int key, t_window *window)
{
	if (key == 53)
	{
		ft_mem_free(window->map);
		mlx_destroy_window(window->mlx, window->mlx_win);
		exit(0);
	}
	else if (key == 126 || key == 13)
		move(window, "up");
	else if (key == 124 || key == 2)
		move(window, "right");
	else if (key == 125 || key == 1)
		move(window, "down");
	else if (key == 123 || key == 0)
		move(window, "left");
	return (0);
}

void	game(t_map *map, int ll)
{
	t_window	window;

	ft_memset(&window, 0, sizeof(window));
	window.mlx = mlx_init();
	if (!window.mlx)
		ft_free_and_print(map->map, 1, "");
	window.mlx_win = mlx_new_window(window.mlx, PX * ll,
			PX * map->line, "so_long");
	if (!window.mlx_win)
		ft_free_and_print(map->map, 1, "");
	game2(map->map, &window);
	window.i = map->i;
	window.j = map->j;
	window.c = map->collectibles;
	window.map = map->map;
	mlx_hook(window.mlx_win, 2, 0, handle_keypress, &window);
	mlx_hook(window.mlx_win, 17, 0, handle_des, &window);
	mlx_loop(window.mlx);
}

void	game2(char **map, t_window *win)
{
	int	w;
	int	h;

	win->collectible = mlx_xpm_file_to_image(win->mlx, "./col.xpm", &w, &h);
	win->exit = mlx_xpm_file_to_image(win->mlx, "./exit.xpm", &w, &h);
	win->player = mlx_xpm_file_to_image(win->mlx, "./up.xpm", &w, &h);
	win->wall = mlx_xpm_file_to_image(win->mlx, "./ww.xpm", &w, &h);
	win->fre = mlx_xpm_file_to_image(win->mlx, "./empty.xpm", &w, &h);
	win->down = mlx_xpm_file_to_image(win->mlx, "./down.xpm", &w, &h);
	win->right = mlx_xpm_file_to_image(win->mlx, "./right.xpm", &w, &h);
	win->left = mlx_xpm_file_to_image(win->mlx, "./left.xpm", &w, &h);
	ft_check_xpm(win, map);
	ft_put_imgs(map, win);
}
