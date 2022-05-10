/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:12:19 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/10 12:54:53 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*ft_import_image(void *img, t_game *game, char *path)
{
	int	height;
	int	width;

	img = mlx_xpm_file_to_image(game->ptr, path, &width, &height);
	if (!img)
		ft_error(4, game);
	return (img);
}

void	ft_import_xpm(t_game *game)
{
	game->wall = ft_import_image(game->wall, game, "./sprites/wall.xpm");
	game->floor = ft_import_image(game->floor, game, "./sprites/floor.xpm");
	game->exit = ft_import_image(game->exit, game, "./sprites/exit.xpm");
	game->player.ptr = ft_import_image(game->player.ptr, game,
			"./sprites/player.xpm");
	game->collec.ptr = ft_import_image(game->collec.ptr, game,
			"./sprites/collec.xpm");
}
