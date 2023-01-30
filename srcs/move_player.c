/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:42:10 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/30 11:18:49 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"

void	move_up(t_data *data)
{
	if (is_exit(data, data->player_y - 1, data->player_x) == 1)
	{
		if (data->tab[data->player_y - 1][data->player_x] != 'E')
		{
			data->tab[data->player_y][data->player_x] = '0';
			data->player_y -= 1;
			data->tab[data->player_y][data->player_x] = 'P';
			data->moves++;
			ft_printf("%d\n", data->moves);
		}
	}
}

void	move_down(t_data *data)
{
	if (is_exit(data, data->player_y + 1, data->player_x) == 1)
	{
		if (data->tab[data->player_y + 1][data->player_x] != 'E')
		{
			data->tab[data->player_y][data->player_x] = '0';
			data->player_y += 1;
			data->tab[data->player_y][data->player_x] = 'P';
			data->moves++;
			ft_printf("%d\n", data->moves);
		}
	}
}

void	move_right(t_data *data)
{
	if (is_exit(data, data->player_y, data->player_x + 1) == 1)
	{
		if (data->tab[data->player_y][data->player_x + 1] != 'E')
		{
			data->tab[data->player_y][data->player_x] = '0';
			data->player_x += 1;
			data->tab[data->player_y][data->player_x] = 'P';
			data->moves++;
			ft_printf("%d\n", data->moves);
		}
	}
}

void	move_left(t_data *data)
{
	if (is_exit(data, data->player_y, data->player_x - 1) == 1)
	{
		if (data->tab[data->player_y][data->player_x - 1] != 'E')
		{
			data->tab[data->player_y][data->player_x] = '0';
			data->player_x -= 1;
			data->tab[data->player_y][data->player_x] = 'P';
			data->moves++;
			ft_printf("%d\n", data->moves);
		}
	}
}

int	move_player(int keycode, t_data *data)
{
	if ((keycode == W || keycode == UP)
		&& data->tab[data->player_y - 1][data->player_x] != '1')
		move_up(data);
	if ((keycode == S || keycode == DOWN)
		&& data->tab[data->player_y + 1][data->player_x] != '1')
		move_down(data);
	if ((keycode == D || keycode == RIGHT)
		&& data->tab[data->player_y][data->player_x + 1] != '1')
		move_right(data);
	if ((keycode == A || keycode == LEFT)
		&& data->tab[data->player_y][data->player_x - 1] != '1')
		move_left(data);
	ft_put_into_window(data, data->tab);
	return (0);
}
