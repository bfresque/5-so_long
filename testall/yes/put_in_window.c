/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:31:21 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/23 09:37:05 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
monPoint.x = 10; // On travaille sur une variable, on utilise le "point"
pointeur->x = 10; // On travaille sur un pointeur, on utilise la flèche
*/

void	ft_init_images(t_image *img)
{
	printf("\ndebut de l'init image\n");

	void	*mlx;

	mlx = mlx_init();
	
	img->img_width = 80;
	img->img_height = 80;
	
	img->path_background = "images/sand.xpm";
	img->img_background = mlx_xpm_file_to_image(mlx, img->path_background, &img->img_width, &img->img_height);
	img->path_wall = "images/cactus.xpm";
	img->img_wall = mlx_xpm_file_to_image(mlx, img->path_wall, &img->img_width, &img->img_height);
	img->path_player = "images/cowboy.xpm";
	img->img_player = mlx_xpm_file_to_image(mlx, img->path_player, &img->img_width, &img->img_height);
	img->path_collect = "images/gold.xpm";
	img->img_collect = mlx_xpm_file_to_image(mlx, img->path_collect, &img->img_width, &img->img_height);
	img->path_exit = "images/horse.xpm";
	img->img_exit = mlx_xpm_file_to_image(mlx, img->path_exit, &img->img_width, &img->img_height);

	printf("\n***FIN de l'init image***\n");

}

void	ft_put_into_window(t_data *data)
{
	int x;
	int y;
	int offset_x;
	int offset_y;

	offset_x = 0;
	offset_y = 0;
	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 5)
		{
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_sand, offset_x, offset_y);
			else if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_cactus, offset_x, offset_y);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_cowboy, offset_x, offset_y);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_gold, offset_x, offset_y);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_horse, offset_x, offset_y);
			offset_x += data->img->img_width;
			x++;
		}
		offset_x = 0;
		offset_y += data->img->img_height;
		y++;
	}
}