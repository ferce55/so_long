/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:45:58 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/12 11:14:57 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_close(t_game *game, char *msg)
{
	printf("%s\n", msg);
	exit(0);
	return (0);
}

static void	ft_save_collect(t_game *game, int y, int x)
{
	game->collec.count--;
	game->map->matrix[game->player.y + y][game->player.x + x] = '0';
}

static void	ft_refresh_game(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->ptr, game->win, game->floor,
		64 * game->player.x, 64 * game->player.y);
	game->player.y += y;
	game->player.x += x;
	mlx_put_image_to_window(game->ptr, game->win, game->floor,
		64 * game->player.x, 64 * game->player.y);
	mlx_put_image_to_window(game->ptr, game->win, game->player.ptr,
		64 * game->player.x, 64 * game->player.y);
}

static void	ft_change_pos(t_game *game, int y, int x)
{
	char	pos;

	pos = game->map->matrix[game->player.y + y][game->player.x + x];
	if (pos == '1' || (pos == 'E' && game->collec.count > 0))
		return ;
	game->nmoves++;
	printf("Movements count: %zu\n", game->nmoves);
	if (pos == 'C')
		ft_save_collect(game, y, x);
	else if (pos == 'E' && game->collec.count == 0)
		on_close(game, "You Won!");
	ft_refresh_game(game, y, x);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		on_close(game, "Closed");
	else if (keycode == 0 || keycode == 123)
		ft_change_pos(game, 0, -1);
	else if (keycode == 2 || keycode == 124)
		ft_change_pos(game, 0, 1);
	else if (keycode == 13 || keycode == 126)
		ft_change_pos(game, -1, 0);
	else if (keycode == 1 || keycode == 125)
		ft_change_pos(game, 1, 0);
	return (0);
}
