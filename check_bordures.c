/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bordures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:43:50 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/12 10:54:27 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"
#include "includes/so_long.h"
#include <stdio.h>

int	ft_check_first_line(char **tab)
{
	int	i;
	int	j;
	int	first;

	i = 0;
	j = 0;
	first = 0;
	while (tab[j][i])
	{
		if (tab[0][i] == '1')
			first++;
		i++;
	}
	if (i == first)
		return (1);
	else
		return (0);
}

int	ft_check_begin_line(char **tab)
{
	int	j;
	int	begin;

	j = 0;
	begin = 0;
	while (tab[j])
	{
		if (tab[j][0] == '1')
			begin++;
		j++;
	}
	if (j == begin)
		return (1);
	else
		return (0);
}

int	ft_check_end_line(char **tab)
{
	int	j;
	int	end;
	int	lenght;

	j = 0;
	end = 0;
	lenght = ft_strlen(tab[0]) - 1;
	while (tab[j])
	{
		if (tab[j][lenght] == '1')
			end++;
		j++;
	}
	if (j == end)
		return (1);
	else
		return (0);
}

int	ft_check_last_line(char **tab)
{
	int	j;
	int	i;
	int	last;

	i = 0;
	j = 0;
	last = 0;
	while (tab[j])
		j++;
	j--;
	while (tab[j][i])
	{
		if (tab[j][i] == '1')
			last++;
		i++;
	}
	if (i == last)
		return (1);
	else
		return (0);
}
