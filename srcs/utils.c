/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:35:05 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/17 10:35:01 by bfresque         ###   ########.fr       */
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

void maxi_free(char **tab, char **dup)
{
	ft_free_tab(tab);
	ft_free_tab(dup);
}
