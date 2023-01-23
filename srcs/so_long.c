/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:27:06 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/23 15:15:34 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"

int	close_game(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	close_game_esc(int key)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
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

	ft_put_into_window(&data, data.tab);

	mlx_hook(data.mlx_win, 2, 1, close_game_esc, NULL);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_game, NULL);
	mlx_loop(data.mlx);
	free(data.tab);
	return (0);
}
