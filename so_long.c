/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:27:06 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/09 17:16:35 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
/*
1- mettre la map dans un tableau en utilisant GNL, join et split
2- La carte doit contenir E=1, C>=1 et P=1 
3- La carte doit être de forme rectangulaire ou carre
4- check si 1er ligne, derniere ligne debut et fin sont = 1
5- vérifier s’il existe un chemin valide
6- Faire attention qu'un C ne soit pas bloque derriere un E
6- Si une erreur le programme doit quitter et retourner "Error\n"
*/

int	ft_verif_obj(char **tab)
{
	int exit = 0;
	int collecte = 0;
	int perso = 0;
	int i = 0;
	int j = 0;
	
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == 'E')
				exit++;
			if (tab[j][i] == 'C')
				collecte++;
			if (tab[j][i] == 'P')
				perso++;
			i++;
		}
		j++;
	}
	printf("%d \n", exit);
	printf("%d \n", collecte);
	printf("%d \n", perso);
	return (0);
}

char	**ft_put_in_tab(char *map)
{
	char	*s1;
	char	*s2;
	int		fd;
	char	**tab;

	s1 = "";
	s2 = "";
	fd = open(map, O_RDONLY);
	while (s2 = get_next_line(fd))
	{
		s1 = ft_strjoin(s1, s2);
		free(s2);
	}
	tab = ft_split(s1, '\n');

	//==================== test ====================
	int i = 0;
	while (tab[i])
	{
		printf("%s \n", tab[i]);
		i++;
	}
	//==================== test ====================
	
	ft_verif_obj(tab);
	return (tab);
}

void main ()
{
	ft_put_in_tab("map1.ber");
}
