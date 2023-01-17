/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:08:04 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/17 10:29:18 by bfresque         ###   ########.fr       */
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

#endif