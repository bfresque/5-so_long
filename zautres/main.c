// int	ft_count_i(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[0][i])
// 		i++;
// 	return (i);
// }

// int	ft_count_j(char **tab)
// {
// 	int	j;

// 	j = 0;
// 	while (tab[j])
// 		j++;
// 	return (j);
// }

// void	ft_free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 		free(tab[i++]);
// 	free(tab);
// }

// void maxi_free(char **tab, char **dup)
// {
// 	ft_free_tab(tab);
// 	ft_free_tab(dup);
// }

// char	*read_file(char *map_file)
// {
// 	char	*s1;
// 	char	*s2;
// 	int		fd;
// 	char	*temp;
// 	printf("\nici\n");
// 	fd = open(map_file, O_RDWR);
// 	if (fd <= 0)
// 	{
// 		ft_printf("%s", "\nError: To opening file.\n\n");
// 		return (NULL);
// 	}

// 	s1 = ft_calloc(sizeof(char), 1);
// 	s2 = get_next_line(fd);
// 	while (s2)
// 	{
// 		temp = s1;
// 		s1 = ft_strjoin(temp, s2);
// 		free(temp);
// 		free(s2);
// 		s2 = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (s1);
// }

// char	**load_map_file(char *map_file)
// {
// 	char	*s1;
// 	char	**tab;

// 	s1 = read_file(map_file);
// 	if (!s1)
// 		return (NULL);
// 	check_lignes(s1);
// 	tab = ft_split(s1, '\n');
// 	free(s1);
// 	return (tab);
// }

// char	**ft_tabdup(char **tab)
// {
// 	int		i;
// 	char	**dup;

// 	i = 0;
// 	while (tab[i])
// 		i++;
// 	dup = (char **)malloc(sizeof(char *) * (i + 1));
// 	i = 0;
// 	while (tab[i])
// 	{
// 		dup[i] = ft_strdup(tab[i]);
// 		i++;
// 	}
// 	dup[i] = 0;
// 	return (dup);
// }

// char	**ft_put_in_tab(char *map_file)
// {
// 	char	**tab;
// 	char	**dup;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	tab = load_map_file(map_file);
// 	while (tab[j])
// 		j++;
// 	while (tab[0][i])
// 		i++;
// 	ft_nb_obj(tab);
// 	check_map(tab);
// 	dup = ft_tabdup(tab);
// 	if (dup == NULL)
// 	{
// 		ft_free_tab(tab);
// 		return (NULL);
// 	}
// 	block_exit(j, i, dup);
// 	check_path(j, i, dup);
// 	maxi_free(tab, dup);
// 	return (tab);
// }

// typedef struct s_image {
// 	void    *img_background;
// 	void    *img_player;
// 	void    *img_exit;
// 	void    *img_wall;
// 	void    *img_collect;

// 	char    *path_player;
// 	char    *path_background;
// 	char    *path_wall;
// 	char    *path_collect;
// 	char    *path_exit;

// 	int     img_height;
// 	int     img_width;
// }               t_image;

// typedef struct s_data {
// 	void    *mlx_ptr;
// 	void    *mlx_win;
// 	int     windows_width;
// 	int     windows_height;
// 	int     map_width;
// 	int     map_height;
// 	char    **map;
// 	t_image  img;
// }               t_data;


// void    print_img(t_data *data, void *img, int x, int y)
// {
// 	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, data->img.img_width * x, data->img.img_height * y);
// }

// void    put_background(t_data *data)
// {
// 	int     i;
// 	int     j;

// 	i = 0;
// 	j = 0;
// 	while (data->map[j] != NULL)
// 	{
// 		while (data->map[j][i] != '\0')
// 		{
// 			if (data->map[j][i] == '1')
// 				print_img(data, data->img.img_wall, i, j);
// 			else if (data->map[j][i] == '0')
// 				print_img(data, data->img.img_background, i, j);
// 			else if (data->map[j][i] == 'P')
// 				print_img(data, data->img.img_player, i, j);
// 			else if (data->map[j][i] == 'E')
// 				print_img(data, data->img.img_exit, i, j);
// 			else if (data->map[j][i] == 'C')
// 				print_img(data, data->img.img_collect, i, j);
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// }

// void    ft_init_images(t_data *data)
// {
// 	data->img.img_height = 80;
// 	data->img.img_width = 80;
// 	data->img.path_background = "images/background.xpm";
// 	data->img.path_wall = "images/wall.xpm";
// 	data->img.path_collect = "images/collect.xpm";
// 	data->img.path_player = "images/player.xpm";
// 	data->img.path_exit = "images/exit.xpm";

// 	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_wall, &(data->img.img_width), &(data->img.img_height));
// 	if (!data->img.img_wall)
// 	{
// 		ft_printf("%s", "\nError: Failed to load image %s\n\n", data->img.path_wall);
// 		exit(1);
// 	}
// 	data->img.img_background = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_background, &(data->img.img_width), &(data->img.img_height));
// 	if (!data->img.img_background)
// 	{
// 		ft_printf("%s", "\nError: Failed to load image %s\n\n", data->img.path_background);
// 		exit(1);
// 	}
// 	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_exit, &(data->img.img_width), &(data->img.img_height));
// 	if (!data->img.img_exit)
// 	{
// 		ft_printf("%s", "\nError: Failed to load image %s\n\n", data->img.path_exit);
// 		exit(1);
// 	}
// 	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_collect, &(data->img.img_width), &(data->img.img_height));
// 	if (!data->img.img_collect)
// 	{
// 		ft_printf("%s", "\nError: Failed to load image %s\n\n", data->img.path_collect);
// 		exit(1);
// 	}
// 	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr, data->img.path_player, &(data->img.img_width), &(data->img.img_height));
// 	if (!data->img.img_player)
// 	{
// 		ft_printf("%s", "\nError: Failed to load image %s\n\n", data->img.path_player);
// 		exit(1);
// 	}
// 	data->windows_width = data->map_width * data->img.img_width;
// 	data->windows_height = data->map_height * data->img.img_height;
// 	data->mlx_win = mlx_new_window(data->mlx_ptr, data->windows_width, data->windows_height, "Mon jeu");
// 	put_background(data);
// 	mlx_loop(data->mlx_ptr);
// }

// int     main(int ac, char **av)
// {
// 	t_data data;

// 	data.mlx_ptr = mlx_init();
// 	data.map_width = 20;
// 	data.map_height = 20;
// 	printf("\nhey\n");
// 	data.map = ft_put_in_tab(av[1]);
// 	ft_init_images(&data);
// 	return (0);
// }
