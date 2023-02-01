/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:35:05 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/01 14:26:52 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_i(char **tab)
{
	int	i;

	i = 0;
	while (tab[0][i])
		i++;
	return (i);
}

int	ft_count_j(char **tab)
{
	int	j;

	j = 0;
	while (tab[j])
		j++;
	return (j);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	block_exit(int o, int a, char **tab)
{
	int	y;
	int	x;

	y = position_perso_j(o, a, tab, 'E');
	x = position_perso_i(o, a, tab, 'E');
	tab[y][x] = '1';
}
