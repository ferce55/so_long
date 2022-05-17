/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:43:44 by ricardo           #+#    #+#             */
/*   Updated: 2022/05/14 16:10:02 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	start_game(t_game *game)
{
	int	height;
	int	width;

	height = game->map->nline * 64;
	width = game->map->lline * 64;
	game->ptr = mlx_init();
	game->win = mlx_new_window(game->ptr, width, height, "So_Antifa (1312)");
	ft_import_xpm(game);
	ft_init_map(game);
	return (0);
}
