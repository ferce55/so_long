/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:23:46 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/04/07 10:47:43 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_errormsg(char *str, t_map *map)
{
	ft_putstr_fd(str, 1);
	ft_freestruc(map);
	exit(1);
}

static void ft_freematrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free (matrix);
}

void ft_freestruc(t_map *map)
{
	ft_freematrix(map->matrix);
	free(map);
}

int	ft_error(int ecode, t_map *map)
{
	if (ecode == 0)
		ft_errormsg("Error\nEl numero de argumentos es erroneo", map);
	if (ecode == 1)
		ft_errormsg("Error\nEl nombre del mapa es erroneo", map);
	if (ecode == 2)
		ft_errormsg("Error\nEl mapa no es valido", map);
	if (ecode == 3)
		ft_errormsg("Error\nFallo en Reserva de memoria", map);
	return (0);
}
