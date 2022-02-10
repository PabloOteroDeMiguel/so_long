/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:14:14 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/10 11:33:01 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(t_matrix **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
	//	printf("M%i->%p\n", i, matrix[i]);
	//	printf("libero?\n");
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
