/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:03:48 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/12 11:27:36 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"
#include "includes/so_long.h"
#include <stdio.h>

int	check_lignes(char *str)
{
	int	i;
	int	check;

	i = 0;
	if (str[i] == '\n')
	{
		printf("%s", "Error: first character cannot be a newline.\n"); // ALERTE PUT MY FT_PRINF
		free(str);
		exit(1);
	}
	check = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			check++;
			if (check >= 2)
			{
				printf("%s", "Error: more than two consecutive newlines.\n"); // ALERTE PUT MY FT_PRINF
				free(str);
				exit(1);
			}
		}
		else
			check = 0;
		i++;
	}
}

int	ft_check_lenght_line(char **tab)
{
	int	j;
	int	i;
	int	yes;

	i = 0;
	j = 0;
	yes = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
			i++;
		if (tab[j + 1])
		{
			if (ft_strlen(tab[j]) == ft_strlen(tab[j + 1]))
				yes++;
		}
		j++;
	}
	if (yes == (j - 1))
		return (1);
	else
		return (0);
}

int	check_map(char **tab)
{
	if (ft_check_lenght_line(tab) == 1 && ft_check_first_line(tab) == 1
		&& ft_check_last_line(tab) == 1 && ft_check_begin_line(tab) == 1
		&& ft_check_end_line(tab) == 1)
		return (1);
	else
	{
		printf("%s", "Error: The map aren't a closed rectangle.\n"); // ALERTE PUT MY FT_PRINF
		ft_free_tab(tab);
		exit(1);
	}
}
