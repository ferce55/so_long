/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:10:57 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/14 16:52:02 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_print_collec(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->ptr, game->win, game->collec.ptr, 64 * x,
		64 * y);
	game->collec.count++;
}

static void	ft_print_player(t_game *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	mlx_put_image_to_window(game->ptr, game->win, game->player.ptr, 64 * x,
		64 * y);
}

static void	ft_map_to_window(char **matrix, t_game *game, int y, int x)
{
	if (matrix[y][x] == 1)
		mlx_put_image_to_window(game->ptr, game->win, game->wall,
			64 * x, 64 * y);
	else
	{
		mlx_put_image_to_window(game->ptr, game->win, game->floor,
			64 * x, 64 * y);
		if (matrix[y][x] == 'C')
			ft_print_collec(game, x, y);
		if (matrix[y][x] == 'P')
			ft_print_player(game, x, y);
		if (matrix[y][x] == 'E')
			mlx_put_image_to_window(game->ptr, game->win, game->exit,
				64 * x, 64 * y);
	}
}

void	ft_init_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->nline)
	{
		x = 0;
		while (y < game->map->lline)
		{
			x++;
			ft_map_to_window(game->map->matrix, game, y, x);
		}
		y++;
	}
}
