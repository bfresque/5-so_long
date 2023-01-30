/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:27:06 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/30 17:42:15 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"

int	close_game_mouse(t_data *data)
{
	ft_free_tab(data->tab);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	close_game_esc(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_free_tab(data->tab);
		exit(EXIT_SUCCESS);
		return (EXIT_SUCCESS);
	}
	return (-1);
}

int	is_collectible(t_data *data)
{
	int	collect;

	collect = ft_count_obj(data->tab, 'C');
	return (collect);
}

int	is_exit(t_data *data, int y, int x)
{
	if (is_collectible(data) == 0)
	{
		if (data->tab[y][x] == 'E')
		{
			ft_free_tab(data->tab);
			exit(EXIT_SUCCESS);
			return (EXIT_SUCCESS);
		}
	}
	return (1);
}

void	error_map_file(int ac, char **av)
{
	int fd;

	if (av[1] != "*.ber")
	{
		ft_printf("%s", "\nError: name file must be in .ber\n\n");
		exit(1);
	}
	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
	{
		ft_printf("%s", "\nError: Cannot open a Directory.\n\n");
		exit(1);
	}
	if (ac != 2)
	{
		ft_printf("%s", "\nError: Invalid number of arguments\n\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_image	img;
	int		j;
	int		i;

	error_map_file(ac, av);
	data.mlx = mlx_init();
	data.img = &img;
	data.mlx_ptr = data.mlx;
	data.tab = ft_put_in_tab(av[1]);
	ft_init_images(data.img);
	data.window_width = ft_count_i(data.tab) * 80;
	data.window_height = ft_count_j(data.tab) * 80;
	data.mlx_win = mlx_new_window(data.mlx, data.window_width,
			data.window_height, "so_long");
	j = ft_count_j(data.tab);
	i = ft_count_i(data.tab);
	data.player_x = position_perso_i(j, i, data.tab, 'P');
	data.player_y = position_perso_j(j, i, data.tab, 'P');
	ft_put_into_window(&data, data.tab);
	mlx_hook(data.mlx_win, 2, 1L << 0, move_player, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, close_game_esc, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_game_mouse, &data);
	mlx_loop(data.mlx);
	free(data.tab);
}
