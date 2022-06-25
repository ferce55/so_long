/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:43:44 by ricardo           #+#    #+#             */
/*   Updated: 2022/06/25 14:06:24 by rsarri-c         ###   ########.fr       */
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
	game->win = mlx_new_window(game->ptr, width, height, "So_Long");
	ft_import_xpm(game);
	ft_init_map(game);
	mlx_hook(game->win, 17, 1L << 1, on_close, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->ptr);
	return (0);
}
