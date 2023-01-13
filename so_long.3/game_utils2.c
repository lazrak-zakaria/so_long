/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:22:34 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/13 13:43:46 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_do_move(t_window *win, int p_x, int p_y, char *c)
{
	void	*p;

	p = ft_img_rotate(win, c[0]);
	if (c[1] == 'T')
	{
		ft_putnbr(++win->total_move, 1);
		ft_putchar('\n', 1);
	}
	if (win->map[win->i][win->j] == 'E' && !win->c)
	{
		ft_mem_free(win->map);
		write(1, "WIN\n", 5);
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}
	if (win->map[win->i][win->j] == 'C')
		win->c--;
	win->map[p_x][p_y] = '0';
	win->map[win->i][win->j] = 'P';
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->fre,
		p_y * PX, p_x * PX);
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		p, win->j * PX, win->i * PX);
}

void	*ft_img_rotate(t_window *win, char c)
{
	void	*p;

	if (c == 'U')
		p = win->player;
	else if (c == 'R' )
		p = win->right;
	else if (c == 'D')
		p = win->down;
	else
		p = win->left;
	return (p);
}
