/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:43:23 by potero            #+#    #+#             */
/*   Updated: 2022/02/11 11:50:44 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_border(int x, int y, t_matrix **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (matrix[i][j].pos_x == 0 || matrix[i][j].pos_x == x - 1
					|| matrix[i][j].pos_y == 0 || matrix[i][j].pos_y == y - 1)
				matrix[i][j].border = 1;
			else
				matrix[i][j].border = 0;
			j++;
		}
		i++;
	}
}

void	create_matrix(char *file, int x, int y, t_matrix **matrix)
{
	char	*str;
	int		map;
	int		ij[2];

	map = open(file, O_RDONLY);
	if (map == -1)
		error_map_no(0);
	ij[0] = 0;
	while (ij[0] < x)
	{
		str = get_next_line(map);
		ij[1] = 0;
		matrix[ij[0]] = malloc(sizeof(t_matrix) * y);
		if (!matrix[ij[0]])
			memory_error(matrix);
		while (ij[1] < y)
		{
			matrix[ij[0]][ij[1]].pos_x = ij[0];
			matrix[ij[0]][ij[1]].pos_y = ij[1];
			matrix[ij[0]][ij[1]].value = str[ij[1]];
			ij[1]++;
		}
		free(str);
		ij[0]++;
	}
}

void	read_map(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (game->matrix[i][j].value != 'C' &&
					game->matrix[i][j].value != 'P' &&
						game->matrix[i][j].value != 'E' &&
							game->matrix[i][j].value != '0' &&
								game->matrix[i][j].value != '1')
				error_map(2, game->matrix);
			j++;
		}
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
	if (game->exit != 1 || game->player != 1 || game->collectibles < 1)
		error_map(1, game->matrix);
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
				if (matrix[i][j].value != 49)
					error_map(1, matrix);
			j++;
		}
		i++;
	}
}
