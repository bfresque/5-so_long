/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:31:18 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/24 16:57:38 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
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

int	check_path(int o, int a, char **tab)
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
				ft_printf("%s", "\nError: The path aren't good !\n\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	ultimate_check_path(int o, int a, char **dup)
{
	char **dupdup;

	dupdup = ft_tabdup(dup);
	if (dupdup == NULL)
		return (0);
	if (check_path(o, a, dup) == 0)
	{
		ft_free_tab(dup);
		ft_free_tab(dupdup);
		return(0);
	}
	block_exit(o, a, dupdup);
	if (check_path(o, a, dupdup) == 0)
	{
		ft_free_tab(dup);
		ft_free_tab(dupdup);
		return(0);
	}
	return(1);
}