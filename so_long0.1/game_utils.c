/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:29:40 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/09 12:29:42 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_xpm(t_window *win, char **map)
{
	int	f;

	f = (!win->player || !win->collectible || !win->exit
			|| !win->fre || !win->wall);
	if (f)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		ft_free_and_print(map, 1, "ERROR: mlx_xpm_file_to_image");
	}
}

void	ft_put_imgs(char **map, t_window *win)
{
	int	i;

	i = -1;
	while (map[++i])
		ft_put_imgs2(map[i], win, i);
}

void	ft_put_imgs2(char *map, t_window *win, int i)
{
	int	j;

	j = -1;
	while (map[++j])
	{
		if (map[j] == 'P')
			mlx_put_image_to_window (win->mlx, win->mlx_win,
				win->player, j * PX, i * PX);
		else if (map[j] == 'C')
		{
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->fre, j * PX, i * PX);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->collectible, j * PX, i * PX);
		}
		else if (map[j] == '1')
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->wall, j * PX, i * PX);
		else if (map[j] == '0')
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->fre, j * PX, i * PX);
		else
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->exit, j * PX, i * PX);
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
	if (win->map[win->i][win->j] == '1' ||
		(win->map[win->i][win->j] == 'E' && win->c))
	{
		win->i = player_now_x;
		win->j = player_now_y;
		return ;
	}
	ft_do_move(win, player_now_x, player_now_y);
}

void	ft_do_move(t_window *win, int player_now_x, int player_now_y)
{
	ft_putnbr(++win->total_move);
	ft_putchar('\n');
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
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->fre,
		player_now_y * PX, player_now_x * PX);
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		win->fre, win->j * PX, win->i * PX);
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		win->player, win->j * PX, win->i * PX);
}
