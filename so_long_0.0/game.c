#include "so_long.h"

// mlx_loop_hook(data.mlx_ptr, handle_no_event, &data)
void	game2(char **mem, t_window *window);
void	up(t_window *window);
void 	down(t_window *window);
void 	left(t_window *window);

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	
	return (0);
}
void		right(t_window * window);

int	handle_keypress(int keysym, t_window *window)
{
	
	if (keysym == 53)
	{	mlx_destroy_window(window->mlx, window->mlx_win); exit(0);}
	else if (keysym == 126)
		up( window);
	else if (keysym == 124)
		right(window);
	else if (keysym == 125)
		down(window);
	else if (keysym == 123)
		left(window);	
	printf("Keypress: %d\n", keysym);
	return (0);
}

void	game(t_map *map, int ll, char **mem)
{
	t_window window;

	window.mlx = mlx_init();
	printf(" %d \n" ,map->i);
	
	window.mlx_win = mlx_new_window(window.mlx, 50 * ll , 50 * map->line, "GAME");
	game2(mem, &window);
		//printf("**%d**\n", map->i);
	window.i = map->i;
	window.j = map->j;
	window.map = map->map;
	//mlx_loop_hook(window.mlx, handle_no_event, &window);
	mlx_hook(window.mlx_win, 2, 0, &handle_keypress, &window);
	//right(map, &window);
	//game3();
	//printf("finloop\n");
	mlx_loop(window.mlx);
}

void	up( t_window *window)
{
	int i = window->i;
	int j = window->j;
	printf("%d ____ %d\n", i, j);
	if (window->map[i - 1][j]== '1')
		return ;
	// if (window->map[i - 1][j] == 'C' )
	// {
	// 		window->collectibles--;
	// }
	printf("up up\n");
	window->map[i][j] = '0';
	window->map[i - 1][j] = 'P';
	window->i = i - 1;
	window->j = j;;
	int w = 0;
	int h = 0;
	void	*fre = mlx_xpm_file_to_image(window->mlx, "./img2.xpm", &w, &h);
	mlx_put_image_to_window(window->mlx, window->mlx_win, fre, j*50, i*50);
	mlx_put_image_to_window(window->mlx, window->mlx_win, fre, j*50, (i-1)*50);
	
	void	*player = mlx_xpm_file_to_image(window->mlx, "./img5.xpm", &w, &h);
	mlx_put_image_to_window (window->mlx, window->mlx_win, player, j*50, ((i-1)*50));
	//game2( window->map, window);
}

void right(t_window *window)
{
	int i = window->i;
	int j = window->j;
	printf("right %d ____ %d\n", i, j);
	if (window->map[i][j+1]== '1')
		return ;
	// if (window->map[i - 1][j] == 'C' )
	// {
	// 	window->collectibles--;
	// }
	printf("right\n");
	window->map[i][j] = '0';
	window->map[i][j+1] = 'P';
	window->j = j+1;;
	int w = 0;
	int h = 0;
	void	*fre = mlx_xpm_file_to_image(window->mlx, "./img2.xpm", &w, &h);
	mlx_put_image_to_window(window->mlx, window->mlx_win, fre, j*50, i*50);
	mlx_put_image_to_window(window->mlx, window->mlx_win, fre, (j+1)*50, i*50);

	void	*player = mlx_xpm_file_to_image(window->mlx, "./img5.xpm", &w, &h);
	mlx_put_image_to_window (window->mlx, window->mlx_win, player, (j+1)*50, ((i)*50));
	// game2( window->map, window);
}

void down(t_window *window)
{
	int i = window->i;
	int j = window->j;
	printf("down %d ____ %d\n", i, j);
	if (window->map[i + 1][j]== '1')
		return ;
	// if (window->map[i - 1][j] == 'C' )
	// {
	// 	window->collectibles--;
	// }
	printf("down\n");
	window->map[i][j] = '0';
	window->map[i+1][j] = 'P';
	window->i = i+1;;
	int w = 0;
	int h = 0;
	void	*fre = mlx_xpm_file_to_image(window->mlx, "./img2.xpm", &w, &h);
	mlx_put_image_to_window(window->mlx, window->mlx_win, fre, j*50, i*50);
	mlx_put_image_to_window(window->mlx, window->mlx_win, fre, (j)*50, (i+1)*50);

	void	*player = mlx_xpm_file_to_image(window->mlx, "./img5.xpm", &w, &h);
	mlx_put_image_to_window (window->mlx, window->mlx_win, player, (j)*50, ((i+1)*50));
	// game2( window->map, window);
}
void left(t_window *window)
{
	int i = window->i;
	int j = window->j;

	if (window->map[i][j - 1]== '1')
		return ;
	window->map[i][j] = '0';
	window->map[i][j - 1] = 'P';
	window->j = j - 1;;
	int w = 0;
	int h = 0;
	void	*fre = mlx_xpm_file_to_image(window->mlx, "./img2.xpm", &w, &h);
	mlx_put_image_to_window(window->mlx, window->mlx_win, fre, j*50, i*50);
	mlx_put_image_to_window(window->mlx, window->mlx_win, fre, (j - 1)*50, i*50);

	void	*player = mlx_xpm_file_to_image(window->mlx, "./img5.xpm", &w, &h);
	mlx_put_image_to_window (window->mlx, window->mlx_win, player, (j - 1)*50, ((i)*50));
	// game2( window->map, window);
}
void	game2(char **mem, t_window *window)
{
	int w = 0;
	int h = 0;
	//printf("here\n");
	void	*coin = mlx_xpm_file_to_image(window->mlx, "./img4.xpm", &w, &h);
	void	*door = mlx_xpm_file_to_image(window->mlx, "./img3.xpm", &w, &h);
	void	*player = mlx_xpm_file_to_image(window->mlx, "./img5.xpm", &w, &h);
	void	*wall = mlx_xpm_file_to_image(window->mlx, "./wall.xpm", &w, &h);
	void	*fre = mlx_xpm_file_to_image(window->mlx, "./img2.xpm", &w, &h);
	int i = -1;
	while(mem[++i])
	{
		int j = -1;
		printf("%s\n", mem[i]);
		while (mem[i][++j])
		{
			//printf("here3\n");
			if (mem[i][j] == 'P')
				 mlx_put_image_to_window (window->mlx, window->mlx_win, player, j*50, (i*50));
			else if (mem[i][j] == 'C')
				 mlx_put_image_to_window(window->mlx, window->mlx_win, coin, j*50, i*50);
			else if (mem[i][j] == '1')
				 mlx_put_image_to_window(window->mlx, window->mlx_win, wall, j*50, i*50);
			else if (mem[i][j] == '0')
				mlx_put_image_to_window(window->mlx, window->mlx_win, fre, j*50, i*50);
			else
				mlx_put_image_to_window(window->mlx, window->mlx_win, door, j*50, i*50);
		}
	}
}