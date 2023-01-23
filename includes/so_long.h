/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:08:04 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/23 14:53:03 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../minilibx/mlx.h"
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

typedef struct	s_image {
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

typedef struct	s_data {
	void	*mlx;
	void	*mlx_ptr;
	void	*mlx_win;
	char	**tab;
	int		tab_width;
	int		tab_height;
	int		window_width;
	int		window_height;
	int		moves;
	struct	s_image *img;
}				t_data;

/****************************    CHECK LINE    *********************************/
int		ft_check_first_line(char **tab);
int		ft_check_begin_line(char **tab);
int		ft_check_end_line(char **tab);
int		ft_check_last_line(char **tab);
int		ft_check_lenght_line(char **tab);
int		check_map(char **tab);
void	check_lignes(char *str);

/****************************    CHECK ITEMS    *********************************/
int		ft_nb_obj(char **tab);

/****************************    CHECK TAB      *********************************/
char	**ft_tabdup(char **tab);
char	**ft_put_in_tab(char *map_file);

/****************************    CHECK PATH    *********************************/
int		check_path(int n, int m, char **tab);
void	block_exit(int o, int a, char **tab);

/****************************    UTILS         *********************************/
int		ft_count_i(char **tab);
int		ft_count_j(char **tab);
void	maxi_free(char **tab, char **dup);
void	ft_free_tab(char **tab);

/*************************************A SUPPRIMER *****************************/
void    print_tab(char **tab);//SUPPR
void    print_dup(char **dup);//SUPPR
// void	get_lines(char *map_file, t_data *data);
void	get_map(char *map_file, t_data *data);
void	ft_init_images(t_image *img);
void	ft_put_into_window(t_data *data, char **tab);


#endif