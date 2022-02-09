/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_matrix_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:27:48 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/09 16:12:22 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	matrix_size(char *file, int *x, int *y)
{
	int		map;
	int		i;

	map = open(file, O_RDONLY);
	if (map == -1)
		error_map(0);
	i = 0;
	while (get_next_line(map))
	{
		i++;
	}
	*x = i;
	close(map);
	matrix_size_y(file, *x, y);
}

void	matrix_size_y(char *file, int x, int *y)
{
	char	*str;
	int		map;
	int		i;
	int		aux;

	map = open(file, O_RDONLY);
	if (map == -1)
		error_map(0);
	aux = 0;
	i = 0;
	while (i < x)
	{
		str = get_next_line(map);
		*y = ft_strlen(str);
		if (i == 0)
			aux = *y;
		else if (*y != aux)
			error_map(1);
		aux = *y;
		free(str);
		i++;
	}
	*y = *y - 1;
	close(map);
}
