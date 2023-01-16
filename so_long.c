/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:27:06 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/16 17:36:47 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	*read_file(char *map_file)
{
	char	*s1;
	char	*s2;
	int		fd;
	char	*temp;

	fd = open(map_file, O_RDWR);
	if (fd <= 0)
	{
		ft_printf("%s", "Error: Topening file for writing.\n");
		return (NULL);
	}
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

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**dup;

	i = 0;
	while (tab[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	**ft_put_in_tab(char *map_file)
{
	char	**tab;
	char	**dup;

	tab = load_map_file(map_file);
	dup = ft_tabdup(tab);
	if (tab == NULL)
		return (NULL);
	print_tab(tab);//A SUPPRIMER
	ft_nb_obj(tab);
	check_map(tab);
	block_exit(ft_count_j(tab), ft_count_i(tab), dup);
	if (check_path(ft_count_j(tab), ft_count_i(tab), dup))
	{
		print_dup(dup);//A SUPPRIMER
		ft_free_tab(tab);
		ft_free_tab(dup);
	}
	else
	{
		ft_free_tab(tab);
		ft_free_tab(dup);
	}
	return (tab);
}

int	main(void)
{
	ft_put_in_tab("map1.ber");
}
