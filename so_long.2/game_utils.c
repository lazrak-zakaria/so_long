/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:29:40 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/12 15:27:10 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_xpm(t_window *win, char **map)
{
	int	f;

	f = (!win->player || !win->collectible || !win->exit
			|| !win->fre || !win->wall || !win->down
			|| !win->left || !win->right);
	if (f)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		ft_putstr("Error\n");
		ft_free_and_print(map, 1, "mlx_xpm_file_to_image");
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
	int		player_now_x;
	int		player_now_y;
	char	c[2];

	player_now_x = win->i;
	player_now_y = win->j;
	c[0] = ft_target_place(win, s);
	c[1] = 'T';
	if (win->map[win->i][win->j] == '1'
		|| (win->map[win->i][win->j] == 'E' && win->c))
	{
		win->i = player_now_x;
		win->j = player_now_y;
		c[1] = 'F';
	}
	ft_do_move(win, player_now_x, player_now_y, c);
}

char	ft_target_place(t_window *win, char *s)
{
	char	c;

	if (ft_cmp(s, "up", 2))
	{
		win->i--;
		c = 'U';
	}
	else if (ft_cmp(s, "right", 5))
	{
		win->j++;
		c = 'R';
	}
	else if (ft_cmp(s, "down", 4))
	{
		win->i++;
		c = 'D';
	}
	else
	{
		win->j--;
		c = 'L';
	}
	return (c);
}
