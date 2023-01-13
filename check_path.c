/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:31:18 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/13 14:47:08 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>

int	position_perso_i(int n, int m, char **tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++j < n)
	{
		i = -1;
		while (++i < m)
			if (tab[j][i] == 'P')
				return i;
	}
	return (-1);
}

int	position_perso_j(int n, int m, char **tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++j < n)
	{
		i = -1;
		while (++i < m)
			if (tab[j][i] == 'P')
				return j;
	}
	return (-1);
}

void replace_adjacent(int x, int y, int n, int m, char **tab) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return;
	}
	if (tab[x][y] != '1') {
		tab[x][y] = '1';
		replace_adjacent(x + 1, y, n, m, tab);
		replace_adjacent(x - 1, y, n, m, tab);
		replace_adjacent(x, y + 1, n, m, tab);
		replace_adjacent(x, y - 1, n, m, tab);
	}
}

void check_path(int n, int m, char **tab) {
	int x;
	int y;

	y = position_perso_i(n, m, tab);
	x = position_perso_j(n, m, tab);
	replace_adjacent(x, y, n, m, tab);
}
