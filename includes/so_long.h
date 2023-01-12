/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:08:04 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/12 11:26:15 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

int ft_check_first_line(char **tab);
int ft_check_begin_line(char **tab);
int ft_check_end_line(char **tab);
int ft_check_last_line(char **tab);
int	ft_check_lenght_line(char **tab);
int check_map(char **tab);
int check_lignes(char *str);
int	ft_nb_obj(char **tab);
void	ft_free_tab(char **tab);


#endif