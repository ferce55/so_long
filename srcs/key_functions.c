/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:45:58 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/17 16:28:40 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_close(t_game *game, char *msg)
{
	printf("%s\n", msg);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		on_close(game, "Closed");
	return (0);
}
