/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:43:23 by potero            #+#    #+#             */
/*   Updated: 2022/02/09 11:53:31 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	matrix_size(char *file, int *x, int *y)
{
	char	*str;
	int		map;
	int		i;

	map = open(file, O_RDONLY);
	if (map == -1)
		error_map(0);
	i = 0;
	while ((str = get_next_line(map))) /*cuento filas y compruebo que todas sean de la misma long*/
	{
		*y  = ft_strlen(str);
		if (*x == 0)
			i = *y;
		else if (*y != i)
			error_map(1);
		i = *y ;
		free(str);
		*x = *x + 1;
	}
	*y = *y - 1; /*salto de linea*/
	close(map);
}

void	create_matrix(char *file, int x, int y, t_matrix **matrix)
{
	char	*str;
	int		map;
	int		i;
	int		j;

	map = open(file, O_RDONLY);
	if (map == -1)
		error_map(0);
	i = 0;
	while ((str = get_next_line(map)))
	{
		j = 0;
		matrix[i] = malloc(sizeof(t_matrix) * y);
		if (!matrix[i])
			exit (0); // Crear función para liberar <i
		while (j < y)
		{
			matrix[i][j].pos_x = i;	
			matrix[i][j].pos_y = j;
			matrix[i][j].value = str[j];
			if (matrix[i][j].pos_x == 0 || matrix[i][j].pos_x == x - 1 
					|| matrix[i][j].pos_y == 0 || matrix[i][j].pos_y == y - 1)
				matrix[i][j].border = 1;
			else
				matrix[i][j].border = 0;
			j++;
		}
		free(str);
		i++;
	}
}
void	read_matrix(t_game *game, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	game->collectibles = 0;
	game->player = 0;
	game->exit = 0;
	while (j < x)
	{
		i = 0;
		while (i < y)
		{
			if (game->matrix[j][i].value == 'C')
				game->collectibles++;
			if (game->matrix[j][i].value == 'P')
				game->player++;
			if (game->matrix[j][i].value == 'E')
				game->exit++;
			i++;
		}
	j++;
	}
	if (game->exit != 1 || game->player != 1)
		error_map(1);
//	printf("Exit: %d\n", game->exit);
//	printf("Collectibles: %d\n", game->collectibles);
//	printf("Players: %d\n", game->player);
}

void	border(t_matrix **matrix, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{	
		j = 0;
		while (j < y)
		{
			if (matrix[i][j].border == 1)
			{
			//	printf("%i,%i->b(%i,%i)v\n", i, j, matrix[i][j].border, matrix[i][j].value);
				if (matrix[i][j].value != 49) // es un char no un int
					error_map(1);
			}
			j++;
		}
		i++;
	}
}