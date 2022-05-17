/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:23:46 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/17 16:24:19 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//////////////////cambiar todas las limpiezas de memoria de las estructuras
static int	ft_errormsg(char *str, t_game *game)
{
	printf("%s", str);
	ft_freestruc(game);
	exit(1);
}

static void	ft_freematrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free (matrix);
}

int	get_line_iter(char *str, char *line)
{
	int	i;

	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

void	ft_freestruc(t_game *game)
{
	free(game->wall);
	free(game->floor);
	free(game->exit);
	if (game->map)
		ft_freematrix(game->map->matrix);
	free(game->map);
	free(game);
}

int	ft_error(int ecode, t_game *game)
{
	if (ecode == 0)
		ft_errormsg("Error\nEl numero de argumentos es erroneo", game);
	if (ecode == 1)
		ft_errormsg("Error\nEl nombre del gamea es erroneo", game);
	if (ecode == 2)
		ft_errormsg("Error\nEl mapa no es valido", game);
	if (ecode == 3)
		ft_errormsg("Error\nFallo en Reserva de memoria", game);
	if (ecode == 4)
		ft_errormsg("Error\nno se puede crear la imagen", game);
	return (0);
}
