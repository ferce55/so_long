/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:43:44 by ricardo           #+#    #+#             */
/*   Updated: 2022/05/10 12:07:38 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	start_game(t_game *game)
{
	int	height;
	int	width;

	height = game->map.nline * 64;
	width = game->map.lline * 64;
	game->ptr = mlx_init();
	game->win = mlx_new_window(game->ptr, width, height, "So Antifa (1312)");
	ft_import_xmp(game);
	return (0);
}
