/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:08:04 by bfresque          #+#    #+#             */
/*   Updated: 2024/12/17 13:43:48 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../includes/minilibx-linux/mlx.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/so_long.h"
# include "../includes/ft_printf.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

typedef struct s_image{
	int		img_width;
	int		img_height;
	void	*img_ground;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	char	*path_ground;
	char	*path_wall;
	char	*path_player;
	char	*path_collect;
	char	*path_exit;
}				t_image;

typedef struct s_data {
	void			*mlx;
	void			*mlx_win;
	char			**tab;
	int				tab_width;
	int				tab_height;
	int				player_x;
	int				player_y;
	int				offset_x;
	int				offset_y;
	int				sizex;
	int				sizey;
	int				window_width;
	int				window_height;
	int				moves;
	struct s_image	*img;
}				t_data;

/***********************    CHECK LINE    ****************************/
int		ft_check_first_line(char **tab);
int		ft_check_begin_line(char **tab);
int		ft_check_end_line(char **tab);
int		ft_check_last_line(char **tab);
int		check_map(char **tab);
void	check_lignes(char *str);

/***********************    CHECK ITEMS    ***************************/
int		ft_nb_obj(char **tab);
int		ft_count_obj(char **tab, char obj);

/***********************    CHECK TAB      ***************************/
char	**ft_tabdup(char **tab);
void	ft_put_in_tab(t_data *data, char *map_file);//changement

/***********************    CHECK PATH    ****************************/
int		ultimate_check_path(int o, int a, char **dup);
int		position_perso_i(int o, int a, char **tab, char find);
int		position_perso_j(int o, int a, char **tab, char find);

/***********************    UTILS         ****************************/
int		ft_count_i(char **tab);
int		ft_count_j(char **tab);
void	ft_free_tab(char **tab);
void	block_exit(int o, int a, char **tab);

/*******************     CLOSE GAME          **************************/
void	destroy(t_data *data);
int		close_game_esc(int keycode, t_data *data);
int		close_game_mouse(t_data *data);
int		is_exit(t_data *data, int y, int x);

/***********************    MAIN          ****************************/
void	ft_init_images(t_data *data, t_image *img);
void	ft_put_into_window(t_data *data, char **tab);
int		is_exit(t_data *data, int y, int x);
int		move_player(int keycode, t_data *data);
void	destroy(t_data *data);
int		is_collectible(t_data *data);

#endif