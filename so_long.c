/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:27:06 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/12 11:36:18 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"
#include "includes/so_long.h"
#include <stdio.h>

/*
// 1- mettre la map dans un tableau en utilisant GNL, join et split
// 2- La carte doit contenir E=1, C>=1 et P=1 
// 3- La carte doit être de forme rectangulaire ou carre
// 4- check si 1er ligne, derniere ligne debut et fin sont = 1
5- vérifier s’il existe un chemin valide
6- Faire attention qu'un C ne soit pas bloque derriere un E
7- Si une erreur le programme doit quitter et retourner "Error\n"
*/

char	*read_file(char *map_file)
{
	char	*s1;
	char	*s2;
	int		fd;
	char	*temp;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	s1 = ft_calloc(sizeof(char), 1);
	s2 = get_next_line(fd);
	while (s2)
	{
		temp = s1;
		s1 = ft_strjoin(temp, s2);
		free(temp);
		free(s2);
		s2 = get_next_line(fd);
	}
	close(fd);
	return (s1);
}

char	**load_map_file(char *map_file)
{
	char	*s1;
	char	**tab;

	s1 = read_file(map_file);
	if (!s1)
		return (NULL);
	check_lignes(s1);
	tab = ft_split(s1, '\n');
	free(s1);
	return (tab);
}

char	**ft_put_in_tab(char *map_file)
{
	char	**tab;
	int i;

	i = 0;
	tab = load_map_file(map_file);
	if (tab == NULL)
		return (NULL);

	/******************TEST***********************/
	printf("\nMAP : \n\n");
	while(tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("\nCheck item : %d\n\n", ft_nb_obj(tab));
	printf("\nCheck map : %d\n\n", check_map(tab));
	/******************TEST***********************/
	check_map(tab);
	ft_free_tab(tab);
	return (tab);
}
void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	main()
{
	ft_put_in_tab("map1.ber");
}
