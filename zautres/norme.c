/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:58:27 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/20 10:52:20 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_image {
	void	*img_background;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;

	char	*path_player;
	char	*path_background;
	char	*path_wall;
	char	*path_collect;
	char	*path_exit;

	int		img_height;
	int		img_width;
}				t_image;

typedef struct s_contenu
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	background;
}				t_contenu;

typedef struct s_data {
	void	*mlx_ptr;
	void	*mlx_win;
	int		windows_width;
	int		windows_height;
	int		map_width;
	int		map_height;
	char	**map;
	t_contenu	cont;
	t_image	img;
}				t_data;

void	set_content(t_contenu *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->background = '0';
	content->collect = 'C';
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, data->img.img_width * x, data->img.img_height * y);
}

void	put_background(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map[j] != NULL)
	{
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == data->cont.wall)
				print_img(data, data->img.img_wall, i, j);
			if (data->map[j][i] == data->cont.background)
				print_img(data, data->img.img_background, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}


void ft_init_images(t_data *data)
{
    data->img.img_height = 80;
    data->img.img_width = 80;
    data->img.path_background = "images/background.xpm";
    data->img.path_wall = "images/wall.xpm";
    data->img.path_collect = "images/collect.xpm";
    data->img.path_player = "images/player.xpm";
    data->img.path_exit = "images/exit.xpm";

    data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_wall, &(data->img.img_width), &(data->img.img_height));
    if (!data->img.img_wall)
    {
        fprintf(stderr, "Error: Failed to load image %s\n", data->img.path_wall);
        exit(1);
    }
    data->img.img_background = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_background, &(data->img.img_width), &(data->img.img_height));
    if (!data->img.img_background)
    {
        fprintf(stderr, "Error: Failed to load image %s\n", data->img.path_background);
        exit(1);
    }
    data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_exit, &(data->img.img_width), &(data->img.img_height));
    if (!data->img.img_exit)
    {
        fprintf(stderr, "Error: Failed to load image %s\n", data->img.path_exit);
        exit(1);
    }
    data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_collect, &(data->img.img_width), &(data->img.img_height));
    if (!data->img.img_collect)
    {
        fprintf(stderr, "Error: Failed to load image %s\n", data->img.path_collect);
        exit(1);
    }
    data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_player, &(data->img.img_width), &(data->img.img_height));
    if (!data->img.img_player)
    {
        fprintf(stderr, "Error: Failed to load image %s\n", data->img.path_player);
        exit(1);
    }

    data->windows_width = data->img.img_width * data->map_width;
    data->windows_height = data->img.img_height * data->map_height;
}

int     main(void)
{
    t_data data;

    data.mlx_ptr = mlx_init();
    data.map_width = 20;
    data.map_height = 20;
    data.map = ft_init_map();
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.windows_width, data.windows_height, "GAME");
	data.map = ft_put_in_tab("../maps/map_1.ber");
    set_content(&data.cont);
    ft_init_images(&data);
    return (0);
}

// void	ft_init_images(t_data *data)
// {
// 	data->img.img_height = 80;
// 	data->img.img_width = 80;
// 	data->img.img_background = "images/background.xpm";
// 	data->img.img_wall = "images/wall.xpm";
// 	data->img.img_collect = "images/collect.xpm";
// 	data->img.img_player = "images/player.xpm";
// 	data->img.img_exit = "images/exit.xpm";

// 	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.img_wall, &(data->img.img_width), &(data->img.img_height));
// 	data->img.img_background = mlx_xpm_file_to_image(data->mlx_ptr, data->img.img_background, &(data->img.img_width), &(data->img.img_height));
// 	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.img_exit, &(data->img.img_width), &(data->img.img_height));
// 	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr, data->img.img_collect, &(data->img.img_width), &(data->img.img_height));
// 	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr, data->img.img_player, &(data->img.img_width), &(data->img.img_height));
// }