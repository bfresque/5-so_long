/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:27:06 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/25 11:47:42 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"

int	close_game(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	move_up(t_data *data, int x, int y)
{
	printf("\nje move_up\n");
	if (data->tab[y - 1][x] == 0)
		data->player_y -= 1;
}

void	move_down(t_data *data, int x, int y)
{
	printf("\nje move_down\n");
	if (data->tab[y + 1][x] == 0)
		data->player_y += 1;
}

void	move_left(t_data *data, int x, int y)
{
	printf("\nje move_left\n");
	if (data->tab[y][x - 1] == 0)
		data->player_x -= 1;
}

void	move_right(t_data *data, int x, int y)
{
	printf("\nje move_right\n");
	if (data->tab[y][x + 1] == 0)
		data->player_x += 1;
}

void	update(t_data *data)
{
	int				x;
	int				y;
	printf("\ndebut update\n");
	x = data->player_x;
	y = data->player_y;
	if (data->player_up != 0)
		move_up(data, x, y);
	else if (data->player_down != 0)
		move_down(data, x, y);
	else if (data->player_left != 0)
		move_left(data, x, y);
	else if (data->player_right != 0)
		move_right(data, x, y);
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	ft_put_into_window(data, data->tab);
	printf("\nfin update\n");
}

int	key_release(int keycode, t_data *data)
{
	printf("\ndebut key_release\n");
	if (keycode == W || keycode == UP)
		data->player_up = 1;
	if (keycode == S || keycode == DOWN)
		data->player_down = 1;
	if (keycode == A || keycode == LEFT)
		data->player_left = 1;
	if (keycode == D || keycode == RIGHT)
		data->player_right = 1;
	update(data);
	printf("\nfin key_release\n");
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	printf("\ndebut key_press\n");
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == W || keycode == UP)
		data->player_up = 1;
	if (keycode == S || keycode == DOWN)
		data->player_down = 1;
	if (keycode == A || keycode == LEFT)
		data->player_left = 1;
	if (keycode == D || keycode == RIGHT)
		data->player_right = 1;
	update(data);
	printf("\nfin key_press\n");
	return (0);
}

int main(int ac, char **av)
{
	t_data data;
	t_image img;

	data.mlx = mlx_init();
	data.img = &img;
	data.mlx_ptr = data.mlx;
	ft_init_images(data.img);

	data.tab = NULL;
	data.tab = ft_put_in_tab(av[1]);
	data.window_width = ft_count_i(data.tab) * 80;
	data.window_height = ft_count_j(data.tab) * 80;
	data.mlx_win = mlx_new_window(data.mlx, data.window_width, data.window_height, "so_long");

	int j = ft_count_j(data.tab);
	int i = ft_count_i(data.tab);
	printf("\n\n %d | %d \n\n", j, i);
	data.player_x = position_perso_i(j, i, data.tab, 'P');
	data.player_y = position_perso_j(j, i, data.tab, 'P');
	printf("\n\n %d | %d \n\n", data.player_x, data.player_y);
	data.player_up = 0;
	data.player_down = 0;
	data.player_left = 0;
	data.player_right = 0;
	ft_put_into_window(&data, data.tab);

	mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_game, &data);
	mlx_loop(data.mlx);
	free(data.tab);
	(void)ac;
	return (0);
}

// void move_player(t_data *data, int player_x, int player_y, char c)
// {
// 	if (c == 'w' && player_y > 0)
// 	{
// 		if (data->tab[player_y - 1][player_x] != '1')
// 		{
// 			data->tab[player_y - 1][player_x] = 'P';
// 			data->tab[player_y][player_x] = '0';
// 		}
// 	}
// 	if (c == 'a' && player_x > 0)
// 	{
// 		if (data->tab[player_y][player_x - 1] != '1')
// 		{
// 			data->tab[player_y][player_x - 1] = 'P';
// 			data->tab[player_y][player_x] = '0';
// 		}
// 	}
// 	if (c == 's' && player_y < ft_count_j(data->tab) - 1)
// 	{
// 		if (data->tab[player_y + 1][player_x] != '1')
// 		{
// 			data->tab[player_y + 1][player_x] = 'P';
// 			data->tab[player_y][player_x] = '0';
// 		}
// 	}
// 	if (c == 'd' && player_x < ft_count_i(data->tab) - 1)
// 	{
// 		if (data->tab[player_y][player_x + 1] != '1')
// 		{
// 			data->tab[player_y][player_x + 1] = 'P';
// 			data->tab[player_y][player_x] = '0';
// 		}
// 	}
// 	ft_put_into_window(data, data->tab);
// }

// int	on_press(int key, t_data *data)
// {
// 	int x;
// 	int y;
// 	int i;
// 	int j;
	
// 	j = ft_count_j(data->tab);
// 	i = ft_count_i(data->tab);
// 	y = position_perso_j(j, i, data->tab, 'P');
// 	x = position_perso_i(j, i, data->tab, 'P');
// 	if (key == ESC)
// 		exit(EXIT_SUCCESS);
// 	else if (key == W)
// 		move_player(data, x, y,'w');
// 	else if (key == A)
// 		move_player(data, x, y, 'a');
// 	else if (key == S)
// 		move_player(data, x, y, 's');
// 	else if (key == D)
// 		move_player(data, x, y, 'd');
// 	return (EXIT_SUCCESS);
// }