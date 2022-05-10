/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:12:19 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/10 12:15:17 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_import_xmp(t_game *game)
{
	game->wall = ft_import_image(game->wall, game->ptr, "./sprites/wall");
}
