/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:11:07 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/10 12:29:16 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r')
		i--;
	else
		error_map_no(3);
	if (str[i] == 'e')
		i--;
	else
		error_map_no(3);
	if (str[i] == 'b')
		i--;
	else
		error_map_no(3);
	if (str[i] == '.')
		i--;
	else
		error_map_no(3);
}
