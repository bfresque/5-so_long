/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:31:44 by bfresque          #+#    #+#             */
/*   Updated: 2023/01/23 09:34:03 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// int main(int ac, char **av)
// {
// 	t_data data;
// 	t_image img;

// 	data.mlx = mlx_init();
// 	data.img = &img;
// 	data.window_width = 720; 
// 	data.window_height = 400;
// 	data.mlx_ptr = data.mlx;
// 	ft_init_images(data.img);
// 	data.mlx_win = mlx_new_window(data.mlx, data.window_width, data.window_height, "so_long");
	
// 	data.tab = ft_put_in_tab(av[1]);

// 	/**************TEST MAP**************/
// 	int i = 0;
// 	printf("\nmap : \n");

// 	while(data.tab[i])
// 	{
// 		printf("%s \n", data.tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	/**************TEST MAP**************/
	
// 	ft_put_into_window(&data);

// 	printf("\n***FIN DE MON MAIN***\n");

// 	mlx_loop(data.mlx);
// 	(void)ac;
// 	return (0);
// }

/*
TO FO POUR LUNDI

1- bien allouer la memoire avec calloc de ma map 
2- calculer les longeur et largeur de mon tab

Pour afficher mon tableau, je segfault apparement car je ne malloc pas la place du tablea
puis je boucle a l infini sur mon 1er [y][x]
*/

int main(int ac, char **av)
{
	t_data data;
	t_image img;

	char **map;

	map = (char **)malloc(sizeof(char *) * 6);
	for (int i = 0; i < 6; i++) {
		map[i] = (char *)malloc(sizeof(char) * 4);
	}

	char vals[6][4] = {
		{'1','1','1','1'},
		{'1','P','0','1'},
		{'1','0','C','1'},
		{'1','0','C','1'},
		{'1','0','E','1'},
		{'1','1','1','1'}
	};
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = vals[i][j];
		}
	}
    data.map = map;

	data.mlx = mlx_init();
	data.img = &img;
	data.windows_width = 320; // AUTOMATISER ICI
	data.windows_height = 480; // AUTOMATISER ICI
	data.mlx_ptr = data.mlx;
	ft_init_images(data.img);
	data.win_ptr = mlx_new_window(data.mlx, data.windows_width, data.windows_height, "so_long");
	
	// data.tab = ft_put_in_tab(av[1]);

	int i = 0;
	printf("\nmap : \n");
	for (i = 0; i < 5; i++)
	{
		int j;
		for (j = 0; j < 6; j++)
		{
			printf("%c", data.map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	ft_put_into_window(&data);

	mlx_loop(data.mlx);
	
	for (int i = 0; i < 5; i++) {
    free(map[i]);
	}
	free(map);
	
	(void)ac;
	return (0);
}


/*CE MAIN AFFICHE BIEN MON TABLEAU
int main(int ac, char **av)
{
    t_data data;
    t_image img;

	char **map;

	map = (char **)malloc(sizeof(char *) * 6);
	for (int i = 0; i < 6; i++) {
		map[i] = (char *)malloc(sizeof(char) * 4);
	}

	char vals[6][4] = {
		{'1','1','1','1'},
		{'1','0','0','1'},
		{'1','0','P','1'},
		{'1','0','C','1'},
		{'1','0','E','1'},
		{'1','1','1','1'}
	};
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = vals[i][j];
		}
	}
    data.tab = map;

	int i = 0;
	printf("\nmap : \n");
	for (i = 0; i < 6; i++)
	{
		int j;
		for (j = 0; j < 4; j++)
		{
			printf("%c", data.tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < 6; i++) {
    free(map[i]);
	}
	free(map);
	
    (void)ac;
    return (0);
}
*/