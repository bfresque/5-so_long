/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:58:27 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/17 10:22:36 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_put_in_tab(char *map_file)
{
	char	**tab;
	char	**dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = load_map_file(map_file);
	while (tab[j])
		j++;
	while (tab[0][i])
		i++;
	ft_nb_obj(tab);
	check_map(tab);
	dup = ft_tabdup(tab);
	if (dup == NULL)
	{
		ft_free_tab(tab);
		return (NULL);
	}
	block_exit(j, i, dup);
	check_path(j, i, dup);
	maxi_free(tab, dup);
	return (tab);
}
