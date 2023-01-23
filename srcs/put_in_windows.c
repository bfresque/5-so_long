/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:42:30 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/23 13:55:26 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_images(t_image *img)
{
	void	*mlx;

	mlx = mlx_init();
	
	img->img_width = 80;
	img->img_height = 80;
	
	img->path_ground = "images/ground.xpm";
	img->img_ground = mlx_xpm_file_to_image(mlx, img->path_ground, &img->img_width, &img->img_height);
	img->path_wall = "images/wall.xpm";
	img->img_wall = mlx_xpm_file_to_image(mlx, img->path_wall, &img->img_width, &img->img_height);
	img->path_player = "images/player.xpm";
	img->img_player = mlx_xpm_file_to_image(mlx, img->path_player, &img->img_width, &img->img_height);
	img->path_collect = "images/collect.xpm";
	img->img_collect = mlx_xpm_file_to_image(mlx, img->path_collect, &img->img_width, &img->img_height);
	img->path_exit = "images/exit.xpm";
	img->img_exit = mlx_xpm_file_to_image(mlx, img->path_exit, &img->img_width, &img->img_height);
}

void	ft_put_into_window(t_data *data, char **tab)
{
	int x;
	int y;
	int sizex;
	int sizey;
	int offset_x;
	int offset_y;

	offset_x = 0;
	offset_y = 0;
	y = 0;
	sizex = ft_count_i(tab);
	sizey = ft_count_j(tab);
	while (y < sizey)
	{
		x = 0;
		while (x < sizex)
		{
			if (data->tab[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img_ground, offset_x, offset_y);
			else if (data->tab[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img_wall, offset_x, offset_y);
			else if (data->tab[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img_player, offset_x, offset_y);
			else if (data->tab[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img_collect, offset_x, offset_y);
			else if (data->tab[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img_exit, offset_x, offset_y);
			offset_x += data->img->img_width;
			x++;
		}
		offset_x = 0;
		offset_y += data->img->img_height;
		y++;
	}
}
