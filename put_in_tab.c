/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:21:18 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/16 17:43:19 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_open_file(char *map_file)
{
	int		fd;
	char	**tab;

	fd = open(map_file, O_RDWR);
	if (fd <= 0)
	{
		ft_printf("%s", "\nError: To opening file for writing.\n\n");
		return (0);
	}
	return (fd);
}

char	*ft_read_file(int fd, char *s1, char *s2)
{
	char	*temp;

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

char	**ft_split_lines(char *s1)
{
	char	**tab;

	check_lignes(s1);
	tab = ft_split(s1, '\n');
	if (tab == NULL)
		return (NULL);
	free(s1);
	return (tab);
}

char	**ft_create_dup(char **tab)
{
	int		j;
	int		i;
	char	**tab;

	i = 0;
	j = 0;
	while (tab[j])
		j++;
	while (tab[0][i])
		i++;
	dup = ft_tabdup(tab);
	block_exit(j, i, dup);
	return (dup);
}

char	**ft_put_in_tab(char *map_file)
{
	int		fd;
	char	*s1;
	char	*s2;
	char	**tab;
	char	**dup;

	fd = ft_open_file(map_file);
	tab = ft_read_file(fd, s1, s2);
	dup = ft_create_dup(tab);
	if (check_path(j, i, dup))
	{
		print_dup(dup);
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
