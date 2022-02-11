/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:57:50 by potero            #+#    #+#             */
/*   Updated: 2022/02/11 11:50:41 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(int e, t_matrix **matrix)
{
	if (e == 0)
	{
		printf("Error\nError de lectura.\n");
		free_matrix(matrix);
		exit(0);
	}
	else if (e == 1)
	{
		printf("Error\nBad map.\n");
		free_matrix(matrix);
		exit(0);
	}
	else if (e == 2)
	{
		printf("Error\nWrong character!!.\n");
		free_matrix(matrix);
		exit(0);
	}
}

void	error_map_no(int e)
{
	if (e == 0)
	{
		printf("Error\nError de lectura.\n");
		exit(0);
	}
	else if (e == 1)
	{
		printf("Error\nBad map.\n");
		exit(0);
	}
	else if (e == 2)
	{
		printf("Error\nWrong character.\n");
		exit(0);
	}
	else if (e == 3)
	{
		printf("Error\nBad file.\n");
		exit(0);
	}
}

void	memory_error(t_matrix **matrix)
{
	printf("Error\nMemory error.\n");
	free_matrix(matrix);
	exit(0);
}
