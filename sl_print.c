/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:14:26 by potero            #+#    #+#             */
/*   Updated: 2022/02/09 16:43:40 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_border(t_matrix **matrix, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	printf("Matrix border:\n");
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			printf("%d", matrix[i][j].border);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_matrix(t_matrix **matrix, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	printf("Matrix:\n");
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			printf("%c", matrix[i][j].value);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_steps(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	printf("Steps: %d\n", game->steps);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		game->mlx.img_w, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.window,
		10, 10, 0x000000000, "STEPS: ");
	mlx_string_put(game->mlx.mlx, game->mlx.window,
		70, 10, 0x000000000, str);
	free(str);
}
