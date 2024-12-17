/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:22:02 by bfresque          #+#    #+#             */
/*   Updated: 2024/12/17 13:45:00 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game_mouse(t_data *data)
{
	destroy(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	close_game_esc(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		destroy(data);
		exit(EXIT_SUCCESS);
		return (EXIT_SUCCESS);
	}
	return (-1);
}

int	is_exit(t_data *data, int y, int x)
{
	if (is_collectible(data) == 0)
	{
		if (data->tab[y][x] == 'E')
		{
			data->moves++;
			ft_printf("Moves counter : \033[0;32m%d\n", data->moves);
			destroy(data);
			exit(EXIT_SUCCESS);
			return (EXIT_SUCCESS);
		}
	}
	return (1);
}

void	destroy_images(t_data *data)
{
	if (data->img->img_wall)
		mlx_destroy_image(data->mlx, data->img->img_wall);
	if (data->img->img_ground)
		mlx_destroy_image(data->mlx, data->img->img_ground);
	if (data->img->img_player)
		mlx_destroy_image(data->mlx, data->img->img_player);
	if (data->img->img_collect)
		mlx_destroy_image(data->mlx, data->img->img_collect);
	if (data->img->img_exit)
		mlx_destroy_image(data->mlx, data->img->img_exit);
}

void	destroy(t_data *data)
{
	if (data->tab)
		ft_free_tab(data->tab);
	destroy_images(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}
