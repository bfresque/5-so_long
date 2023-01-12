/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:43:08 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/12 11:26:31 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"
#include "includes/so_long.h"
#include <stdio.h>

int	ft_count_obj(char **tab, char obj)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == obj)
				count++;
			if (tab[j][i] != '0' && tab[j][i] != '1'
				&& tab[j][i] != 'E' && tab[j][i] != 'C'
				&& tab[j][i] != 'P')
					return (0);
			i++;
		}
		j++;
	}
	return (count);
}

int	ft_nb_obj(char **tab)
{
	int	exitt;
	int	collecte;
	int	perso;

	exitt = ft_count_obj(tab, 'E');
	collecte = ft_count_obj(tab, 'C');
	perso = ft_count_obj(tab, 'P');
	if (exitt == 1 && collecte >= 1 && perso == 1)
		return (1);
	else
	{
		printf("%s", "Error: There is a problem with item initialization.\n"); // ALERTE PUT MY FT_PRINF
		ft_free_tab(tab);
		exit(1);
	}
}
