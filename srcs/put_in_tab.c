/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:21:18 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/02 12:36:21 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*read_file(char *map_file)
{
	char	*s1;
	char	*s2;
	int		fd;
	char	*temp;

	fd = open(map_file, O_RDWR);
	if (fd <= 0)
	{
		ft_printf("%s", "\nError: To opening file.\n\n");
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
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	ft_put_in_tab(t_data *data, char *map_file)
{
	char	**dup;
	int		i;
	int		j;

	data->tab = load_map_file(map_file);
	if (!data->tab)
		exit(1);
	i = ft_count_i(data->tab);
	j = ft_count_j(data->tab);
	ft_nb_obj(data->tab);
	check_map(data->tab);
	dup = ft_tabdup(data->tab);
	if (dup == NULL)
	{
		ft_free_tab(data->tab);
		exit(1);
	}
	if (ultimate_check_path(j, i, dup) == 0)
	{
		ft_free_tab(data->tab);
		exit(1);
	}
	ft_free_tab(dup);
}
