/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:42:30 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/03 10:17:06 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_image(t_data *data)
{
	if (!data->img->img_ground || !data->img->img_wall
		|| !data->img->img_exit || !data->img->img_collect
		|| !data->img->img_player)
	{
		ft_printf("Erreur: One of the images is not found.");
		destroy(data);
		exit(1);
	}
}

void	ft_init_images(t_data *data, t_image *img)
{
	img->img_width = 80;
	img->img_height = 80;
	img->path_ground = "images/ground.xpm";
	img->path_wall = "images/wall.xpm";
	img->path_player = "images/player.xpm";
	img->path_collect = "images/collect.xpm";
	img->path_exit = "images/exit.xpm";
	img->img_ground = mlx_xpm_file_to_image(data->mlx, img->path_ground,
			&img->img_width, &img->img_height);
	img->img_wall = mlx_xpm_file_to_image(data->mlx, img->path_wall,
			&img->img_width, &img->img_height);
	img->img_player = mlx_xpm_file_to_image(data->mlx, img->path_player,
			&img->img_width, &img->img_height);
	img->img_collect = mlx_xpm_file_to_image(data->mlx, img->path_collect,
			&img->img_width, &img->img_height);
	img->img_exit = mlx_xpm_file_to_image(data->mlx, img->path_exit,
			&img->img_width, &img->img_height);
	check_image(data);
}

void	ft_put_into_window_caracter(t_data *data, char c)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_ground, data->offset_x, data->offset_y);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_wall, data->offset_x, data->offset_y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_player, data->offset_x, data->offset_y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_collect, data->offset_x, data->offset_y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_exit, data->offset_x, data->offset_y);
}

void	ft_put_into_window(t_data *data, char **tab)
{
	int	x;
	int	y;

	y = 0;
	data->offset_x = 0;
	data->offset_y = 0;
	data->sizex = ft_count_i(tab);
	data->sizey = ft_count_j(tab);
	while (y < data->sizey)
	{
		x = 0;
		while (x < data->sizex)
		{
			ft_put_into_window_caracter(data, data->tab[y][x]);
			data->offset_x += data->img->img_width;
			x++;
		}
		data->offset_x = 0;
		data->offset_y += data->img->img_height;
		y++;
	}
}
