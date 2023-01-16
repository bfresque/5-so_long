/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:31:18 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/16 15:12:24 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>

int	position_perso_j(int o, int a, char **tab, char find)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < o)
	{
		i = -1;
		while (++i < a)
			if (tab[j][i] == find)
				return (j);
	}
	return (-1);
}

int	position_perso_i(int o, int a, char **tab, char find)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < o)
	{
		i = -1;
		while (++i < a)
			if (tab[j][i] == find)
				return (i);
	}
	return (-1);
}

void	replace_adjacent(int y, int x, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
		j++;
	while (tab[0][i])
		i++;
	if (y < 0 || y >= j || x < 0 || x >= i)
		return ;
	if (tab[y][x] != '1')
	{
		tab[y][x] = '1';
		replace_adjacent(y + 1, x, tab);
		replace_adjacent(y - 1, x, tab);
		replace_adjacent(y, x + 1, tab);
		replace_adjacent(y, x - 1, tab);
	}
}

void	block_exit(int o, int a, char **tab)
{
	int	y;
	int	x;

	y = position_perso_j(o, a, tab, 'E');
	x = position_perso_i(o, a, tab, 'E');
	tab[y][x] = '1';
}

void	check_path(int o, int a, char **tab)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	y = position_perso_j(o, a, tab, 'P');
	x = position_perso_i(o, a, tab, 'P');
	replace_adjacent(y, x, tab);
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == 'E' || tab[j][i] == 'C')
			{
				ft_printf("%s", "\nError: The pass aren't good !\n\n");
				ft_free_tab(tab);
				exit(1);
			}
			i++;
		}
		j++;
	}
}
