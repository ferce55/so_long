/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:23:46 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/10 10:59:21 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//////////////////cambiar todas las limpiezas de memoria de las estructuras
static int	ft_errormsg(char *str, t_game *game)
{
	ft_putstr_fd(str, 1);
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

void	ft_freestruc(t_game *game)
{
	free(game->player.ptr);
	free(game->player);
	free(game->collec.ptr);
	free(game->collec);
	ft_freematrix(game->map.matrix);
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
		ft_errormsg("Error\nEl gamea no es valido", game);
	if (ecode == 3)
		ft_errormsg("Error\nFallo en Reserva de memoria", game);
	return (0);
}
