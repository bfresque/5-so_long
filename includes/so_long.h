/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:08:04 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/16 14:49:41 by bfresque         ###   ########.fr       */
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

int		ft_check_first_line(char **tab);
int		ft_check_begin_line(char **tab);
int		ft_check_end_line(char **tab);
int		ft_check_last_line(char **tab);
int		ft_check_lenght_line(char **tab);
int		check_map(char **tab);
void	check_lignes(char *str);

int		ft_nb_obj(char **tab);

void	ft_free_tab(char **tab);

void	check_path(int n, int m, char **tab);
void	block_exit(int o, int a, char **tab);

/*************************************A SUPPRIMER *****************************/
void print_tab(char **tab);
void print_dup(char **dup);

#endif