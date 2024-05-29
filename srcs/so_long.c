/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:27:06 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/03 10:15:28 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"

int	is_collectible(t_data *data)
{
	int	collect;

	collect = ft_count_obj(data->tab, 'C');
	return (collect);
}

int	extention(char *file_name)
{
	int	ret;

	ret = 0;
	while (*file_name)
		file_name++;
	while (*file_name != '.')
		file_name--;
	if (*file_name == '.')
	{
		file_name++;
		if (*file_name == 'b')
		{
			file_name++;
			if (*file_name == 'e')
			{
				file_name++;
				if (*file_name == 'r')
				{
					file_name++;
					ret = 4;
				}
			}
		}
	}
	return (ret);
}

void	error_map_file(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("%s", "\nError: Invalid number of arguments\n\n");
		exit(1);
	}
	if (extention(av[1]) != 4)
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
}

void	ft_run_window(t_data *data)
{
	ft_init_images(data, data->img);
	data->mlx_win = mlx_new_window(data->mlx, data->window_width,
			data->window_height, "so_long");
	ft_put_into_window(data, data->tab);
	mlx_hook(data->mlx_win, 2, 1L << 0, move_player, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, close_game_esc, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, close_game_mouse, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_image	img;
	int		j;
	int		i;

	error_map_file(ac, av);
	ft_put_in_tab(&data, av[1]);
	data.moves = 0;
	data.mlx = mlx_init();
	data.img = &img;
	data.window_width = ft_count_i(data.tab) * 80;
	data.window_height = ft_count_j(data.tab) * 80;
	if ((data.window_width > 2560) || (data.window_height > 1360))
	{
		ft_free_tab(data.tab);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		ft_printf("%s", "\nError: Size windows.\n\n");
		exit(1);
	}
	j = ft_count_j(data.tab);
	i = ft_count_i(data.tab);
	data.player_y = position_perso_j(j, i, data.tab, 'P');
	data.player_x = position_perso_i(j, i, data.tab, 'P');
	ft_run_window(&data);
}
